// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "IndieGameLabsJamCharacter.h"



// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EnemySprite = CreateDefaultSubobject<UPaperSpriteComponent>("EnemySprite");
	EnemyCapsule = CreateDefaultSubobject<UCapsuleComponent>("EnemyCapsule");
	EnemySprite->SetNotifyRigidBodyCollision(true);

	EnemyCapsule->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	EnemyCapsule->OnComponentHit.AddDynamic(this, &AEnemy::OnCompHit);
	RootComponent = EnemyCapsule;
}



// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ACharacter* pc = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

}

void AEnemy::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == (UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		AIndieGameLabsJamCharacter* pc = (AIndieGameLabsJamCharacter*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		if (pc->GetActorLocation()[2] > this->GetActorLocation()[2] + EnemyCapsule->GetScaledCapsuleHalfHeight())
		{
			UE_LOG(LogTemp, Warning, TEXT("Would Kill"));
		}
		else {

			UE_LOG(LogTemp, Warning, TEXT("Would Take Damage"));
			FVector newLocation;
			FVector currLocation = (pc->GetActorLocation());
			if (pc->direction == 1) {
				UE_LOG(LogTemp, Warning, TEXT("Right"));
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Left"));
				newLocation = FVector(currLocation[0] - 10.0, currLocation[1], currLocation[2]);
				pc->SetActorLocation(newLocation, false);
			}

		}
	}
}
