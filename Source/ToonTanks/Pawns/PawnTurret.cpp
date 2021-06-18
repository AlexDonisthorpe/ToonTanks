// @AlexDonisthorpe 2021


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(FireRateTimer, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::CheckFireCondition()
{
    if(!PlayerPawn) return;

	if(DistanceToPlayer() <= FireRange)
	{
		// Pew Pew
		UE_LOG(LogTemp, Warning, TEXT("PewPew"));
	}

}

float APawnTurret::DistanceToPlayer() const
{
	if(!PlayerPawn) return 0.0f;
	
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

// Called every frame
void APawnTurret::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}