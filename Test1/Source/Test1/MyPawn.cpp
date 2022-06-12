// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// ���𰡸� ���� ���� ��Ʈ ������Ʈ�� ����ϴ�
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// ī�޶�� ���̴� ������Ʈ�� ����ϴ�
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	// ��Ʈ ������Ʈ�� ī�޶�� ���̴� ������Ʈ�� ���Դϴ�. ī�޶� �̰� �� ȸ����ŵ�ϴ�.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	void AMyPawn::Move_XAxis(float AxisValue)
	{
		// �ʴ� 100 ������ �� �Ǵ� �ڷ� �����Դϴ�
		CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}

	void AMyPawn::Move_YAxis(float AxisValue)
	{
		// �ʴ� 100 ������ ������ �Ǵ� �������� �����Դϴ�
		CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}

	void AMyPawn::StartGrowing()
	{
		bGrowing = true;
	}

	void AMyPawn::StopGrowing()
	{
		bGrowing = false;
	}
}