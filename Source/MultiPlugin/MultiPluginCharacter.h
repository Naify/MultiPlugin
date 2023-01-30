// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiPluginCharacter.generated.h"

UCLASS(config = Game)
class AMultiPluginCharacter : public ACharacter
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent *CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent *FollowCamera;

  public:
    AMultiPluginCharacter();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
    float TurnRateGamepad;

  protected:
    void MoveForward(float Value);

    void MoveRight(float Value);

    void TurnAtRate(float Rate);

    void LookUpAtRate(float Rate);

    void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

    void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

  protected:
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;    

  public:
    FORCEINLINE class USpringArmComponent *GetCameraBoom() const
    {
        return CameraBoom;
    }
    FORCEINLINE class UCameraComponent *GetFollowCamera() const
    {
        return FollowCamera;
    }

  public:
    IOnlineSessionPtr OnlineSessionInterface;

  protected:
    UFUNCTION(BlueprintCallable)
    void CreateGameSession();

    UFUNCTION(BlueprintCallable)
    void JoinGameSession();

    void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnFindSessionsComplete(bool bWasSuccessful);
    void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

  private:
    FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
    FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
    TSharedPtr<FOnlineSessionSearch> SessionSearch;
    FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
};
