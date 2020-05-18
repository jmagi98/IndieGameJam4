// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class INDIEGAMELABSJAM_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy(); 

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, Category = "Sprites")
	UPaperSpriteComponent* EnemySprite;
	
	UPROPERTY(EditAnywhere, Category = "Sprites")
	UCapsuleComponent* EnemyCapsule;

	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
