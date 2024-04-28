// Fill out your copyright notice in the Description page of Project Settings.


#include "BirdPawn.h"
#include "BirdPawn.h"
#include "Camera/CameraComponent.h"
#include "PaperFlipbook.h"  // 资产头文件
#include "PaperFlipbookComponent.h" // 组件头文件
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABirdPawn::ABirdPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp")); 	// 为当前对象添加根组件
	BirdRenderComp = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("BirdRenderComp")); 	// 创建组件方法
	BirdRenderComp->SetupAttachment(RootComponent); 	// 设置BirdRender组件依附在根组件下

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("playerCamera")); // 默认X轴方向
	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->SetRelativeRotation(FRotator(0,-90,0)); // 调整相机旋转
	PlayerCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);	// 修改相机的投射模式为正交模式
	PlayerCamera->SetRelativeLocation(FVector(0, 100, 0)); // 调整相机位置
	PlayerCamera->SetOrthoWidth(1000.f);	// 调整相机视口宽度 

	ConstructorHelpers::FObjectFinder<UPaperFlipbook> BirdBookObj(TEXT("PaperFlipbook'/Game/FlappyBird/Anima/Birds/PF_RedBird.PF_RedBird'")); // 加载资产
	BirdRenderComp->SetFlipbook(BirdBookObj.Object);	// 将资产附加到组件上
}
 
// Called when the game starts or when spawned
void ABirdPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABirdPawn::DoFly()
{
	UE_LOG(LogTemp, Log, TEXT("DoFly"));

	BirdRenderComp->SetSimulatePhysics(true); 	// 开启物理模拟
	BirdRenderComp->SetPhysicsLinearVelocity(FVector::ZeroVector); // 清理掉原有的运动速度
	BirdRenderComp->AddImpulse(FVector::UpVector * 400, NAME_None, true);	// 组件添加力
}

// Called every frame
void ABirdPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABirdPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("DoFly"), IE_Pressed, this, &ABirdPawn::DoFly); // 绑定输入事件到对应的回调函数

}

