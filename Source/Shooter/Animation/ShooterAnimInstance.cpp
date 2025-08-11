// Copyright Danny Kay


#include "ShooterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Shooter/ShooterCharacter.h"

#pragma optimize("", off)


void UShooterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}

void UShooterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	UpdateAnimationProperties(DeltaSeconds);
}

void UShooterAnimInstance::UpdateAnimationProperties(float DeltaSeconds)
{
	if (ShooterCharacter == nullptr)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}

	if (ShooterCharacter == nullptr)
	{
		return;
	}

	FVector Velocity = ShooterCharacter->GetVelocity();
	Velocity.Z = 0.f;

	Speed = Velocity.Size();
	bIsInAir = ShooterCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f;
}

#pragma optimize("", on)
