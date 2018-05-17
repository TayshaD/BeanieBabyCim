#ifndef BEANIEBABYSIM_STORAGEBIN_H
#define BEANIEBABYSIM_STORAGEBIN_H

#include <Factors.h>
#include <BeanieBaby.h>
#include <vector>

class StorageBin {
	/**Maximum amount of babies that can be stored at once. Increases upon upgrade.*/
	int max_capacity_ = INIT_STORAGE_CAPACITY;

	/**Whether the bin is currently organized. Determines whether the user can "see" their collectino, because obviously they need to sort through the babies to count them all.*/
	bool is_organized_;

	/**Vector of all the babies being stored.*/
	std::vector<BeanieBaby> babies_stored_;

public:
	static const std::string EMPTY = "Your collection is empty.";

	static const std::string DISORGANIZED = "Your collection is disorganized, there's no telling what's there.";

	static const std::string COLLECTION_BASE = "You have the following items in your collection:";

	int get_count();

	void organize_collection();

	int get_capacity();

	void upgrade_capacity();





};

#endif;