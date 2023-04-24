#include "Actors/SmartObjects/DI_SplineSmartObject.h"
#include "Components/SplineComponent.h"

ADI_SplineSmartObject::ADI_SplineSmartObject() : Super()
{
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline Component"));
	SplineComponent->SetupAttachment(RootComponent);

#if WITH_EDITOR
	SplineComponent->bDrawDebug = true;
#endif
}

void ADI_SplineSmartObject::BeginPlay()
{
	Super::BeginPlay();

	FillSplinePoints();

}

void ADI_SplineSmartObject::FillSplinePoints()
{
	for (int32 Index = 0; Index <= SplineComponent->GetNumberOfSplinePoints(); Index++)
	{
		SplinePoints.Add(SplineComponent->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::World));
	}
}

const TArray<FVector>& ADI_SplineSmartObject::GetSplinePoints()
{
	return SplinePoints;
}


