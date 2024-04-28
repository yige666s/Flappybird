// Copyright Epic Games, Inc. All Rights Reserved.


#include "FlappybirdGameModeBase.h"

#include "BirdPawn.h"

class ABgActor;

AFlappybirdGameModeBase::AFlappybirdGameModeBase()
{
	DefaultPawnClass = ABirdPawn::StaticClass();	
}

void AFlappybirdGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	BgActor =  GetWorld()->SpawnActor<ABgActor>(); // 生成Actor对象
	BgActor->SetActorLocation(FVector(0, -100, 0));  // 设置Actor位置
}
