// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"
class UInputComponent;
UCLASS(config = Game)
class MYPROJECT4_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	void MoveRight(float Val);

	void MoveForward(float Val);

	/** Spring arm for positioning the camera above the ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SkeletalMesh, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	/** Camera to view the ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SkeletalMesh, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

	bool flag;
	int count;
	float MoveImpulse;


};
