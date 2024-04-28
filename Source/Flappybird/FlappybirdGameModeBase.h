// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BgActor.h"
#include "GameFramework/GameModeBase.h"
#include "FlappybirdGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API AFlappybirdGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		AFlappybirdGameModeBase();
protected:
	virtual void BeginPlay() override;
protected:
	UPROPERTY()
	ABgActor* BgActor;
};
