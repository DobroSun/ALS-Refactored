#include "AlsCameraAnimationInstance.h"

#include "AlsCameraComponent.h"
#include "AlsCharacter.h"

void UAlsCameraAnimationInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	AlsCharacter = Cast<AAlsCharacter>(GetOwningActor());
	AlsCamera = Cast<UAlsCameraComponent>(GetSkelMeshComponent());
}

void UAlsCameraAnimationInstance::NativeUpdateAnimation(const float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (AlsCharacter.IsNull() || AlsCamera.IsNull())
	{
		return;
	}

	Stance = AlsCharacter->GetStance();
	Gait = AlsCharacter->GetGait();
	RotationMode = AlsCharacter->GetRotationMode();
	ViewMode = AlsCharacter->GetViewMode();
	LocomotionMode = AlsCharacter->GetLocomotionMode();
	LocomotionAction = AlsCharacter->GetLocomotionAction();

	bRightShoulder = AlsCamera->IsRightShoulder();
}
