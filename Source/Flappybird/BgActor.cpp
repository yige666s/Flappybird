// Fill out your copyright notice in the Description page of Project Settings.


#include "BgActor.h"
#include "BgActor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
ABgActor::ABgActor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; // ����Ҫtick

	BgRenderComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BgRenderComp"));
	SetRootComponent(BgRenderComp); // ����BgRenderΪ�����
}

void ABgActor::RandomBgSprite()
{
	UPaperSprite* BgSprite = LoadObject<UPaperSprite>(nullptr,
		FMath::RandBool() ? TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/bg_day_Sprite.bg_day_Sprite'")
		: TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/bg_night_Sprite.bg_night_Sprite'")); // �����ʲ�
	BgRenderComp->SetSprite(BgSprite); // �����ʲ�
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

