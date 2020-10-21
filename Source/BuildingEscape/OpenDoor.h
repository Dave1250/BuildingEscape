// Copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;

private:
	float CurrentYaw;
	float InitialYaw;
	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
	float DoorOpenTime = 30.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseTime = 80.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.5f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;

	UPROPERTY(EditAnywhere)
	float MassNeededToOpenDoor = 60.f;
};
