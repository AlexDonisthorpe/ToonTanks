// @AlexDonisthorpe 2021

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;
class MatineeCameraShake;
UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

private:
	// Components
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleTrail;

	// Variables
	UPROPERTY(EditDefaultsOnly, Category="Damage")	
	TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Damage", meta = (AllowPrivateAccess = "true"))
	float Damage = 50;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Move", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 1300;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Effects", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* HitParticle;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Effects", meta = (AllowPrivateAccess = "true"))
	USoundBase* HitSound;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Effects", meta = (AllowPrivateAccess = "true"))
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Effects", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UMatineeCameraShake> HitShake;

	// Functions
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

	void IgnoreOwner() const;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
