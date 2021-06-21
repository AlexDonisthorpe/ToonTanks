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

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void APawnTurret::CheckFireCondition()
{
    if(!PlayerPawn || !PlayerPawn->IsPlayerAlive() || DistanceToPlayer() > FireRange) return;

	Fire();
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

	if(!PlayerPawn || DistanceToPlayer() > FireRange) return;
	RotateTurret(PlayerPawn->GetActorLocation());
}