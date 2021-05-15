#pragma once
#include "Box.h"

using namespace std;
using namespace glm;

bool Box::IntersectLocal(Ray3D& ray, HitResult& outHit, double tMin, double tMax) {
	// Optimized ray-box intersection adapted from http://people.csail.mit.edu/amy/papers/box-jgt.pdf

	// Assume box is at the origin, axis-aligned, with bounds from -0.5 to 0.5 in x, y, and z
	double tmin, tmax, tymin, tymax, tzmin, tzmax;

	double bounds[2] = {-0.5, 0.5};

	

























	// Rare, but make sure we don't have a divide-by-zero before calculating t
	if (denom != 0) {
		double newT = numerator / denom;
		if (newT > tMin && newT < tMax) {
			// Check if the hit location is within the bounds of a unit square
			if (IsInUnitSquare(ray.FindLocAtTime(newT))) {
				// Try updating the HitResult with whichever t value was the smallest in the range
				if (outHit.UpdateTMin(newT)) {
					// If the HitResult ended up finding a new minT, update the normal value in the hit result and return true
					outHit.nor = dvec4(0, 1, 0, 0);
					return true;
				}
			}
		}
	}

	// return false if:
	// - Denominator is zero (Ray is parallel to plane)
	// - No t values were found within the given range
	// - No valid t values were found that were less than the hitResult's tmin (hitresult wasn't updated w/a new value)
	return false;
}

glm::dvec4 Box::GetRandomPointOnSurface()
{
	return transf.translation;
}

bool Box::IsInUnitSquare(const glm::vec4& v) const {
	return (v.x > -0.5 && v.x < 0.5) && (v.z > -0.5 && v.z < 0.5);
}
