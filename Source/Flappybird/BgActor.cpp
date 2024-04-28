// Fill out your copyright notice in the Description page of Project Settings.


#include "BgActor.h"
#include "BgActor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
ABgActor::ABgActor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; // 不需要tick

	BgRenderComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BgRenderComp"));
	SetRootComponent(BgRenderComp); // 设置BgRender为根组件
}

void ABgActor::RandomBgSprite()
{
	UPaperSprite* BgSprite = LoadObject<UPaperSprite>(nullptr,
		FMath::RandBool() ? TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/bg_day_Sprite.bg_day_Sprite'")
		: TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/bg_night_Sprite.bg_night_Sprite'")); // 加载资产
	BgRenderComp->SetSprite(BgSprite); // 设置资产
}

// Called when the game starts or when spawned
void ABgActor::BeginPlay()
{
	Super::BeginPlay();
	RandomBgSprite();
}

// Called every frame
void ABgActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABgActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

