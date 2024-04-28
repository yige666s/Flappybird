// Fill out your copyright notice in the Description page of Project Settings.


#include "BirdPawn.h"
#include "BirdPawn.h"
#include "Camera/CameraComponent.h"
#include "PaperFlipbook.h"  // �ʲ�ͷ�ļ�
#include "PaperFlipbookComponent.h" // ���ͷ�ļ�
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABirdPawn::ABirdPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp")); 	// Ϊ��ǰ������Ӹ����
	BirdRenderComp = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("BirdRenderComp")); 	// �����������
	BirdRenderComp->SetupAttachment(RootComponent); 	// ����BirdRender��������ڸ������

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("playerCamera")); // Ĭ��X�᷽��
	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->SetRelativeRotation(FRotator(0,-90,0)); // ���������ת
	PlayerCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);	// �޸������Ͷ��ģʽΪ����ģʽ
	PlayerCamera->SetRelativeLocation(FVector(0, 100, 0)); // �������λ��
	PlayerCamera->SetOrthoWidth(1000.f);	// ��������ӿڿ�� 

	ConstructorHelpers::FObjectFinder<UPaperFlipbook> BirdBookObj(TEXT("PaperFlipbook'/Game/FlappyBird/Anima/Birds/PF_RedBird.PF_RedBird'")); // �����ʲ�
	BirdRenderComp->SetFlipbook(BirdBookObj.Object);	// ���ʲ����ӵ������
}
 
// Called when the game starts or when spawned
void ABirdPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABirdPawn::DoFly()
{
	UE_LOG(LogTemp, Log, TEXT("DoFly"));

	BirdRenderComp->SetSimulatePhysics(true); 	// ��������ģ��
	BirdRenderComp->SetPhysicsLinearVelocity(FVector::ZeroVector); // �����ԭ�е��˶��ٶ�
	BirdRenderComp->AddImpulse(FVector::UpVector * 400, NAME_None, true);	// ��������
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

	PlayerInputComponent->BindAction(TEXT("DoFly"), IE_Pressed, this, &ABirdPawn::DoFly); // �������¼�����Ӧ�Ļص�����

}

