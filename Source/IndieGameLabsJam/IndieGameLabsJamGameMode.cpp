// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "IndieGameLabsJamGameMode.h"
#include "IndieGameLabsJamCharacter.h"

AIndieGameLabsJamGameMode::AIndieGameLabsJamGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AIndieGameLabsJamCharacter::StaticClass();	
}
