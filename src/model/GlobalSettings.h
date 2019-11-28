#pragma once

#include "Listing.h"
#include "Categories.h"
#include "Group.h"
#include <string>

extern model::categories categories;
extern model::listing advertisements;
extern model::group users;

extern string active_user;

extern int category_counter;
extern int advertisement_counter;

extern bool create_verified;
extern bool login_failed;
