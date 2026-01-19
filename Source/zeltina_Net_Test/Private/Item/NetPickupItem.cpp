// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/NetPickupItem.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Framework/NetGameState.h"
#include "GameFramework/Character.h"

// Sets default values
ANetPickupItem::ANetPickupItem()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = SphereComp;
	SphereComp->InitSphereRadius(50.0f);
	SphereComp->SetCollisionProfileName(TEXT("Trigger"));

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void ANetPickupItem::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ANetPickupItem::OnOverlapBegin);
	}

}

void ANetPickupItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority())
	{
		ACharacter* OverlapChar = Cast<ACharacter>(OtherActor);
		if (OverlapChar && OverlapChar->GetController())
		{
			ANetGameState* GS = GetWorld()->GetGameState<ANetGameState>();
			if (GS)
			{
				bool bIsServer = OverlapChar->GetController()->IsLocalController();
				GS->AddScore(bIsServer);
			}
			Destroy();
		}
	}
}


