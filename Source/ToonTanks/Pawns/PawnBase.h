#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ToonTanks/Components/HealthComponent.h"

#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class HealthComponent;
class MatineeCameraShake;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

	private:
	// Components
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Effects", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UMatineeCameraShake> DeathShake;
	

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* DeathParticle;
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* DeathSound;
	
	public:
	APawnBase();

	virtual void HandleDestruction();

	protected:

	void RotateTurret(FVector LookAtTarget) const;
	void Fire();
	
};
