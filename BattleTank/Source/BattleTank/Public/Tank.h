//Copyright Lovely Day Games 2017

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//Returns current health as a percentage between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetCurrentHealthPercent();

	//Called by the engine when actor damage is dealt
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	) override;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 MaxHealth = 20;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = MaxHealth;
};

