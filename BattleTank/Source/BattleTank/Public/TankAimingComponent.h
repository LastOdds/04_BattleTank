//Copyright Lovely Day Games 2017

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	Default
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setput")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Default;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);
};
