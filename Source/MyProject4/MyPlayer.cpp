// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject4.h"
#include "MyPlayer.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"
#include "RobotMesh.h"
// Sets default values
AMyPlayer::AMyPlayer()
{	

	
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = GetCapsuleComponent();
	
	newMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("dreejMesh"));
	ConstructorHelpers::FObjectFinder<USkeletalMesh> newAsset(ANSI_TO_TCHAR("/Game/Meshes/dreej"));
	if (newAsset.Succeeded())
	{
		newMesh->SetSkeletalMesh(newAsset.Object);
		newMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		newMesh->SetMobility(EComponentMobility::Movable);
		UE_LOG(LogTemp, Warning, TEXT("skeletal mesh succeeded"));
		newMesh->SetupAttachment(RootComponent);
	}
	
	
	count = 0;
	MoveImpulse = 250000.0f;

	// Create a camera boom attached to the root (ball)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bAbsoluteRotation = true; // Rotation of the ball should not affect rotation of boom
	SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 1200.f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 3.f;

	// Create a camera and attach to boom
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // We don't want the controller rotating the camera
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
}

void AMyPlayer::MoveRight(float Val)
{
	UE_LOG(LogTemp, Warning, TEXT("move right called %f"), Val);
	const FVector Impulse = FVector(-1.f * Val * MoveImpulse, 0.f, 0.f);
	//newMesh->AddImpulse(Impulse, NAME_None, false);
	if (Val != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Val, true);
	}
}

void AMyPlayer::MoveForward(float Val)
{
	UE_LOG(LogTemp, Warning, TEXT("move fwd called vall %f"), Val);
	const FVector Impulse = FVector(0.f, Val * MoveImpulse, 0.f);
	//newMesh->AddImpulse(Impulse, NAME_None, false);
	if (Val != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Val);
		
	}
}

