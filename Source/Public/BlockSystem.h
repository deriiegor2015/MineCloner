// BlockSystem.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockSystem.generated.h"

// Типи блоків
UENUM(BlueprintType)
enum class EBlockType : uint8
{
    Air = 0 UMETA(DisplayName = "Air"),
    Stone = 1 UMETA(DisplayName = "Stone"),
    Dirt = 2 UMETA(DisplayName = "Dirt"),
    Grass = 3 UMETA(DisplayName = "Grass"),
    Wood = 4 UMETA(DisplayName = "Wood"),
    Leaves = 5 UMETA(DisplayName = "Leaves"),
    Sand = 6 UMETA(DisplayName = "Sand"),
    Water = 7 UMETA(DisplayName = "Water"),
    Lava = 8 UMETA(DisplayName = "Lava"),
    Diamond = 9 UMETA(DisplayName = "Diamond"),
    Gold = 10 UMETA(DisplayName = "Gold"),
    Iron = 11 UMETA(DisplayName = "Iron"),
    Coal = 12 UMETA(DisplayName = "Coal"),
    Obsidian = 13 UMETA(DisplayName = "Obsidian"),
    Gravel = 14 UMETA(DisplayName = "Gravel"),
    Cobblestone = 15 UMETA(DisplayName = "Cobblestone")
};

// Структура блока
USTRUCT(BlueprintType)
struct FBlock
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    EBlockType Type = EBlockType::Air;

    UPROPERTY(BlueprintReadWrite)
    uint8 Health = 100; // 0-100

    FBlock() : Type(EBlockType::Air), Health(100) {}
    FBlock(EBlockType InType) : Type(InType), Health(100) {}
};

// Чанк - 16x16x256 блоків
UCLASS()
class MINECLONER_API AChunk : public AActor
{
    GENERATED_BODY()

public:
    AChunk();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // Блоки (16x16x256)
    UPROPERTY(BlueprintReadWrite)
    FBlock Blocks[16][256][16];

    // Позиція чанка (координати в сітці чанків)
    UPROPERTY(BlueprintReadWrite)
    FIntPoint ChunkCoord;

    // Функції
    UFUNCTION(BlueprintCallable)
    void GenerateChunk(int32 Seed);

    UFUNCTION(BlueprintCallable)
    void PlaceBlock(FVector WorldPos, EBlockType BlockType);

    UFUNCTION(BlueprintCallable)
    EBlockType BreakBlock(FVector WorldPos);

    UFUNCTION(BlueprintCallable)
    FBlock GetBlockAtWorldPos(FVector WorldPos);

    UFUNCTION(BlueprintCallable)
    bool IsValidChunkCoord(int32 X, int32 Y, int32 Z) const;

private:
    void UpdateMesh();
    FVector WorldPosToLocalChunkPos(FVector WorldPos) const;
};

// Система світу - управління чанками
UCLASS()
class MINECLONER_API AWorldManager : public AActor
{
    GENERATED_BODY()

public:
    AWorldManager();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 WorldSeed = 12345;

    UPROPERTY(BlueprintReadWrite)
    TMap<FIntPoint, AChunk*> LoadedChunks;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 RenderDistance = 8; // Кількість чанків для завантаження

    // Функції
    UFUNCTION(BlueprintCallable)
    AChunk* GetOrCreateChunk(FIntPoint ChunkCoord);

    UFUNCTION(BlueprintCallable)
    void PlaceBlockInWorld(FVector WorldPos, EBlockType BlockType);

    UFUNCTION(BlueprintCallable)
    EBlockType BreakBlockInWorld(FVector WorldPos);

    UFUNCTION(BlueprintCallable)
    FBlock GetBlockAtWorld(FVector WorldPos);

    UFUNCTION(BlueprintCallable)
    FIntPoint GetChunkCoordFromWorldPos(FVector WorldPos) const;

    UFUNCTION(BlueprintCallable)
    void UpdateChunksAroundPlayer(FVector PlayerPos);

private:
    void UnloadDistantChunks(FVector PlayerPos);
};