// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "EOS_Gamemode.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_THE_MAZE_API AEOS_Gamemode : public AGameMode
{
	GENERATED_BODY()

		

public:
	virtual  void PostLogin(APlayerController* NewPlayer)override;
	
	
};
