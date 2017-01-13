//Copyright Lovely Day Games 2017

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super as we are replacing the functionality
	
	auto TankFoward = GetOwner()->GetActorForwardVector();
	auto AIFowardIntention = MoveVelocity.GetSafeNormal();

	auto FowardThrow = FVector::DotProduct(TankFoward, AIFowardIntention);
	IntendMoveForward(FowardThrow);
	
	auto RotateThrow = FVector::CrossProduct(AIFowardIntention, TankFoward).Z;
	auto TankName = GetOwner()->GetName();
	IntendRotate(RotateThrow);

	//UE_LOG(LogTemp, Warning, TEXT("Rotate: %f, Forward: %f"), RotateThrow, FowardThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendRotate(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}