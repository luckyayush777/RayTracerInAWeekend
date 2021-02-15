#pragma once

#include"Hittable.h"

#include<vector>
#include<memory>


class HittableList : public Hittable
{

public :
	std::vector<std::shared_ptr<Hittable>> objects;
public :
	HittableList() {}
	HittableList(std::shared_ptr<Hittable> object) { Add(object); }
	void Clear() { objects.clear(); }
	void Add(std::shared_ptr<Hittable> object) 
	{
		objects.push_back(object);
	}

	virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& hitRecord) const override;








};
