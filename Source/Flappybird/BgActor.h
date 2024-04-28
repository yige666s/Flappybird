// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BgActor.generated.h"

class UPaperSpriteComponent;

UCLASS()
class FLAPPYBIRD_API ABgActor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABgActor();

	void RandomBgSprite();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY()
	UPaperSpriteComponent* BgRenderComp;	// 对象组件

};
