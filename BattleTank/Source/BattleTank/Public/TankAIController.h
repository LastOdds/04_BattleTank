//Copyright Lovely Day Games 2017

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	//How close the ai tank can get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AccptenceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;


};
