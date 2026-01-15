// Fill out your copyright notice in the Description page of Project Settings.


#include "CaptureZone.h"
#include "GameStartGameState.h"

// Sets default values
ACaptureZone::ACaptureZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACaptureZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACaptureZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACaptureZone::ZoneUpdate()
{
    std::vector<int> counts; // チームごとのゾーンに入っている人数
    counts.insert(counts.begin(), ALobbyGameMode::MaxPlayers, 0);

    // ゾーンに含まれるプレイヤーを全てループ
    for (auto It = CharactersInZone.CreateIterator(); It; ++It)
    {
        if (!It->IsValid())
        {
            It.RemoveCurrent();
            continue;
        }

        auto ps = It->Get()->GetPlayerState<AGP3PlayerState>();
        if (ps != nullptr)
        {
            // PlayerStateから取得できるTeamIdに応じたcountsを加算
            counts[ps->TeamId]++;
        }
    }

    // 数えた人数が最大の要素を指すcountsのイテレータを取得
    auto itMax = std::ranges::max_element(counts);

    // 人数が最大のチームの数が単独で存在している場合だけ true
    auto isDominant = std::ranges::count(counts, *itMax) == 1;

    if (isDominant)
    {
        UE_LOG(LogTemp, Log, TEXT("Dominant Players=%d"), itMax - counts.begin());
    }
}

