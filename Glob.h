#ifndef GLOB_H
#define GLOB_H

#include<string>
using std::string;

static const string FaunaHeader = "Skeleton,Homeostasis,Habitat,Sub-Habitat,Diet,Social Type,Temperament,Territoriality,Body Mass (kg),Symmetry,Body Frame,Body Shape,BMI,Head,Eyes,Limb Count,Tail(s),Flight,Swimming,Limb Length,Appendages,Dermis,Color,Pattern,Other 1,Other 2,Other 3,Sentience,Hive Sentience,Reproduction,Avg. Young,Sexual Type";
static const string FaunaFile = "Fauna.csv";

static const string FloraHeader = "Type,Habitat,Sub-Habitat,Rarity,Grouping,Size,Body,Branches,Roots,Surface,Color,Leaves,Leaf Place,Leaf Shape,Leaf Surface,Leaf Venation,Leaf #s,Leaf Color,Reproduction,Seeds,Dispersal,Flower Type,Flower Shape,Size,Shape,Pedal Count,Pedal Surface,Flower Location,Flower Scent,Flower Frequency,Flower Color,Stamens & Pistils,Diet,Tropism,Sentience,Sentience Type,Edibility,Prep,Med Prop,Med Prep";
static const string FloraFile = "Flora.csv";

static const int global_error = 9999;

#endif
