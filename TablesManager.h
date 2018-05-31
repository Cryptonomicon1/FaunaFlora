#ifndef TABLESMANAGER_H
#define TABLESMANAGER_H

#include<iostream>
using std::cout;

#include<vector>
using std::vector;
using std::stoi;

#include<string>
using std::string;

#include<cstdlib>
using std::rand;
using std::srand;

#include<ctime>
using std::time;

#include<cmath>
using std::pow;

#include"Table.h"

class TablesManager {
public:
	//Constructor
	TablesManager();

	//Destructor
	~TablesManager();

	//Functions
	vector<string> MakePlant();
	vector<string> MakeAnimal();
	vector<string> getFloraNams();
	vector<string> getFaunaNams();

private:
	//Variables
	vector<Table> FloraTabs;
	vector<string> FloraNams;
	vector<Table> FaunaTabs;
	vector<string> FaunaNams;

	//Functions
	int Roll(int, int);
	int Rnd(float);
	string StrStrip(vector<string>, string);
	string PedalCount();
	int YoungMod(string, string);
	int YoungCount(string);
	int BodyMassIndex(string, string);
	double TorsoLength(float, float);
	float MassS2IMin(string);
	float MassS2IMax(string);
	vector<string> ColorsOf(string, string);
};
//Public
TablesManager::TablesManager() {
	string name;
	vector<string> ins;
	vector<vector<int>> lims;
	vector<string> outs;

	srand(time(NULL));

	// Flora Tables
	//-------------------------------------------------------------------------------------------------------------------------------------------
	// elem 0
	name = "1: Main Flora Type";
	ins = {"only"};
	lims = {{30, 85, 90, 100}};
	outs = {"Woody", "Herbaceous", "Algae", "Fungus"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 1
	name = "2: Primary Habitat";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{5, 10, 99, 100},
			{35, 40, 99, 100},
			{80, 90, 98, 100},
			{10, 40, 99, 100}};
	outs = {"Aquatic", "Sub-Terrestrial", "Terrestrial", "Avian"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 2
	name = "2a: Aquatic Sub-Habitat";
	ins = {"only"};
	lims = {{30, 90, 100}};
	outs = {"Salt Water", "Fresh Water", "Brackish"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 3
	name = "2b: Other Sub-Habitat";
	ins = {"only"};
	lims = {{5, 10, 40, 50, 80, 90, 95, 100}};
	outs = {"Re-Roll", "Desert / Waste", "Plains / Savannah", "Marsh / Swamp / Bog", "Forest / Jungle", "Hills / Scrub", "Mountains", "Tundra"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 4
	name = "2c: Rarity";
	ins = {"only"};
	lims = {{15, 50, 80, 94, 99, 100}};
	outs = {"Very Common", "Common", "Uncommon", "Rare", "Very Rare", "Unique (Extremely Limited Area)"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 5
	name = "3: Grouping";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{20, 40, 80, 100},
			{30, 50, 90, 100},
			{25, 70, 95, 100},
			{25, 70, 95, 100}};
	outs = {"Solitary (1-2)", "Small Patch (1-12)", "Medium Patch (12-120)", "Large Patch (120+)"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 6
	name = "4: Size";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{15, 45, 80, 98, 100},
			{10, 20, 70, 95, 100},
			{2, 15, 65, 85, 100},
			{1, 10, 30, 60, 100}};
	outs = {"Huge (>10m)", "Large (1-10m)", "Average (25cm-1m)", "Small (5-25cm)", "Tiny (<5cm)"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 7
	name = "5: Main Body";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{2, 20, 70, 99, 100},
			{3, 35, 70, 98, 100},
			{70, 75, 85, 99, 100},
			{20, 30, 70, 99, 100}};
	outs = {"Colonial Mass", "Creeper Vine", "Stem / Trunk", "Multiple Stems / Trunks", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 8
	name = "5a: Branches";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{55, 75, 99, 100},
			{45, 50, 85, 100},
			{25, 60, 90, 100},
			{2, 5, 15, 100}};
	outs = {"Radial", "Ordered", "Random", "None"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 9
	name = "5b: Roots";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{35, 37, 84, 93, 95, 99, 100},
			{35, 45, 83, 77, 90, 99, 100},
			{1, 2, 4, 15, 19, 50, 100},
			{3, 9, 15, 20, 30, 90, 100}};
	outs = {"Tap", "Tubers", "Fibrous", "Advantageous", "Bulb", "Rhizoid", "None"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 10
	name = "5c: Surface For";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{30, 40, 70, 84, 97, 99, 100},
			{59, 79, 85, 90, 94, 99, 100},
			{65, 70, 75, 82, 90, 99, 100},
			{65, 70, 75, 82, 90, 99, 100}};
	outs = {"Smooth", "Waxy", "Rough", "Scaly", "Flaky", "Other", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 11
	name = "5d: Color For ";
	ins = {"only"};
	lims = {{5, 10, 20, 45, 50, 55, 60, 65, 70, 80, 85, 90, 95, 100}};
	outs = {"Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Black", "Grey", "White", "Brown", "Silver", "Copper", "Gold", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 12
	name = "5e: Color Pattern For";
	ins = {"only"};
	lims = {{10, 20, 25, 40, 60, 75, 80, 85, 90, 95, 100}};
	outs = {"Spotted", "Mottled", "Patches", "Stripes", "Solid", "Phases", "Translucent", "Iridescent", "Luminescent", "Blushed", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 13
	name = "6: Leaves";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{55, 70, 94, 97, 98, 99, 100},
			{45, 50, 85, 97, 98, 99, 100},
			{2, 3, 10, 11, 15, 30, 100},
			{25, 50, 60, 80, 90, 95, 100}};
	outs = {"Broad", "Needles", "Compound", "Blades", "Scales", "Re-Roll", "None"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 14
	name = "6a: Leaf Location";
	ins = {"only"};
	lims = {{30, 50, 70, 90, 98, 100}};
	outs = {"Terminal", "Branch Points", "Random Interval", "Regular Interval", "Stem / Trunk", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 15
	name = "6b: Leaf Shape";
	ins = {"only"};
	lims = {{3, 6, 10, 14, 17, 21, 25, 28, 32, 35, 39, 43, 47, 51, 56, 58, 61, 64, 67, 70, 72, 75, 78, 81, 83, 87, 92, 96, 98, 100}};
	outs = {"Acicular (Needle)", "Subulate (Awl)", "Lanceolate (Pointed at Both Ends)", "Linear (Parallel Margins & Elongate)", "Falcate (Sickle)", "Spear-Shaped (Pointed Barbbed-Base)", "Hastatae (Triangular Basal Lobes)", "Deltoid (Triangular)", "Rhomboid (Diamond)", "Cuneate (Wedge Accute Base)", "Cordate (Heart Stem in Cleft)", "Obcordate (Heart Stem at Point)", "Ovate (Egg Wide at Base)", "Obovate (Egg Narrow at Base)", "Acuminate (Taper to Long Point)", "Aristate (Spine-Like Tip)", "Orbicular (Circular)", "Obtuse (Bluntly Tipped)", "Elliptic (Oval Small or No Point)", "Reniform (Kidney)", "Spatulate (Spoon)", "Truncate (Squared off Apex)", "Flabellate (Fan Shaped)", "Lobed (Deeply Indented Margins)", "Pinnatisect (Deep Opposite Lobing)", "Poly-Foliate (2-7 Leaflets)", "Palmate (Hand-Like)", "Pedate (Palmate Divided Latteral Lobes)", "Digitate (Finger-Like Lobes)", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 16
	name = "6c: Leaf Margin";
	ins = {"only"};
	lims = {{15, 30, 40, 45, 55, 60, 70, 75, 85, 90, 95, 100}};
	outs = {"Smooth", "Sinuate", "Undulate", "Spiny", "Lobate", "Crenate", "Dentate", "Denticulate", "Serate", "Serrulate", "Ciliate", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 17
	name = "6c: Leaf Surface";
	ins = {"only"};
	lims = {{25, 40, 55, 65, 80, 90, 96, 100}};
	outs = {"Smooth", "Waxy", "Scaly", "Hairy", "Velvety" "Dusty", "Sticky", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 18
	name = "6d: Leaf Venation";
	ins = {"only"};
	lims = {{10, 20, 30, 45, 60, 70, 80, 90, 99, 100}};
	outs = {"Arcute (Secondary Veins Bending Towards Apex)", "Cross-Venulate (Small Veins Connecting Secondary Veins)", "Dichotomous (Veins Branching in Symmetric Pairs)", "Longitudinal (Veins Mostly Aligned Along Axis of Leaf)", "Palmate (Several Primary Veins Diverging from a Point)", "Parallel (Veins Arranged Axially Not Intersecting)", "Pinnate (Secondary Veins Paired Oppositely)", "Reticulate (Smaller Veins Forming a Network)", "None", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 19
	name = "6e: Leaf Numbers";
	ins = {"only"};
	lims = {{20, 40, 60, 95, 100}};
	outs = {"Singles (1)", "Pairs (2)", "Whorls (3-5)", "Clusters (6+)", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 20
	name = "7: Reproduction";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{80, 92, 98, 99, 100},
			{63, 85, 98, 99, 100},
			{2, 6, 90, 99, 100},
			{89, 95, 98, 99, 100}};
	outs = {"Seeds", "Suckers", "Budding / Fragmentation", "Other", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 21
	name = "7a: Seeds";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{5, 50, 94, 99, 100},
			{40, 45, 80, 99, 100},
			{2, 4, 6, 90, 100},
			{2, 4, 6, 90, 100}};
	outs = {"Grain", "Nut", "Fruit", "Spore", "Other"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 22
	name = "7b: Primary Dispersal";
	ins = {"Grain", "Nut", "Fruit", "Spore", "Other"};
	lims = {{20, 40, 60, 98, 100},
			{45, 53, 60, 98, 100},
			{60, 65, 85, 98, 100},
			{40, 83, 90, 98, 100},
			{40, 83, 90, 98, 100}};
	outs = {"Animal", "Wind", "Water", "Gravity", "Other"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 23
	name = "7c: Flower Type";
	ins = {"Grain", "Nut", "Fruit", "Spore", "Other"};
	lims = {{2, 5, 10, 30, 50, 90, 100},
			{2, 40, 60, 80, 90, 95, 100},
			{3, 30, 60, 70, 80, 90, 100},
			{40, 50, 60, 70, 80, 90, 100},
			{10, 20, 30, 50, 70, 90, 100}};
	outs = {"None", "Single", "Pairs", "Bunches", "Compound", "Spray", "Other"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 24
	name = "7d: Flower Shape";
	ins = {"None", "Single", "Pairs", "Bunches", "Compound", "Spray", "Other"};
	lims = {{18, 20, 40, 60, 85, 90, 100},
			{18, 20, 40, 60, 85, 90, 100},
			{20, 25, 30, 45, 80, 90, 100},
			{10, 30, 50, 70, 90, 95, 100},
			{3, 25, 50, 70, 80, 95, 100},
			{10, 15, 25, 40, 80, 90, 100},
			{15, 30, 45, 60, 75, 90, 100}};
	outs = {"Funnel", "Spike", "Disc", "Cone", "Bell", "Sphere", "Complex"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 25
	name = "7e: Flower Size";
	ins = {"only"};
	lims = {{10, 40, 80, 95, 100}};
	outs = {"Tiny (<5mm)", "Small (5-10mm)", "Avg. (1-5cm)", "Large (5-10cm)", "Huge (>10cm)"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 26
	name = "7f: Pedal Shape";
	ins = {"only"};
	lims = {{10, 25, 40, 50, 65, 80, 85, 90, 100}};
	outs = {"Round", "Curly", "Wavy", "Toothed", "Oval", "Blade", "Thread", "Feathery", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 27
	name = "7g: Pedal Surface";
	ins = {"only"};
	lims = {{15, 30, 40, 45, 60, 80, 90, 96, 100}};
	outs = {"Smooth", "Waxy", "Veined", "Scaly", "Hairy", "Velvety", "Dusty", "Sticky", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 28
	name = "7h: Flower Location";
	ins = {"only"};
	lims = {{30, 50, 70, 90, 98, 100}};
	outs = {"Terminal", "Branch Points", "Random Interval", "Regular Interval", "Stem / Trunk", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 29
	name = "7i: Flower Scent";
	ins = {"only"};
	lims = {{10, 60, 80, 95, 100}};
	outs = {"None", "Sweet", "Musky", "Foul", "Other / Specific"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 30
	name = "7j: Flower Frequency";
	ins = {"only"};
	lims = {{40, 60, 90, 100}};
	outs = {"Annual (Once)", "Poly-Annual (2-7 Years)", "Perennial (Yearly)", "Other"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 31
	name = "7k: Flower Pattern";
	ins = {"only"};
	lims = {{8, 13, 20, 30, 50, 55, 60, 65, 70, 84, 89, 92, 95, 100}};
	outs = {"Spotted", "Mottled", "Patches", "Stripes", "Solid", "Phases", "Translucent", "Iridescent", "Luminescent", "Blushed", "Mimicry", "Night Blooming", "Night Closing", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 32
	name = "7l: Stamens";
	ins = {"only"};
	lims = {{10, 30, 70, 100}};
	outs = {"0", "1-3", "4-9", "10+"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 33
	name = "7m: Pistils";
	ins = {"only"};
	lims = {{20, 40, 75, 100}};
	outs = {"0", "1", "2-4", "5+"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 34
	name = "8: Diet";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{89, 90, 95, 98, 99, 100},
			{85, 87, 93, 96, 98, 100},
			{92, 93, 94, 95, 99, 100},
			{5, 8, 90, 94, 99, 100}};
	outs = {"Photo / Chemo-Synthetic", "Predaceous", "Decay", "Parasitic", "Symbiotic", "Other"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 35
	name = "8a: Tropism";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{2, 55, 83, 87, 97, 98, 99, 100},
			{5, 40, 82, 87, 97, 98, 99, 100},
			{20, 35, 60, 85, 90, 94, 98, 100},
			{30, 70, 80, 90, 96, 98, 99, 100}};
	outs = {"None", "Gravity", "Light", "Heat", "Touch", "Motile", "Mobile", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 36
	name = "9: Sentience";
	ins = {"Photo / Chemo-Synthetic", "Predaceous", "Decay", "Parasitic", "Symbiotic", "Other"};
	lims = {{99, 100},
			{97, 100},
			{99, 100},
			{98, 100},
			{98, 100},
			{97, 100}};
	outs = {"Non-Sentient", "Sentient"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 37
	name = "9a: Sentience Type";
	ins = {"only"};
	lims = {{75, 79, 89, 99, 100}};
	outs = {"Instinctual", "Hive", "Animal", "Cunning Animal", "Sapient"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 38
	name = "10: Edibility For";
	ins = {"Woody", "Herbaceous", "Algae", "Fungus"};
	lims = {{40, 65, 80, 99, 100},
			{15, 45, 60, 99, 100},
			{60, 85, 90, 99, 100},
			{30, 60, 86, 99, 100}};
	outs = {"Non-Edible", "Edible", "Nutritious / Tasty", "Medicinal / Other", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 39
	name = "10a: Edible Preparation For";
	ins = {"Edible", "Nutritious / Tasty"};
	lims = {{15, 30, 50, 60, 75, 85, 100},
			{30, 45, 55, 65, 75, 80, 100}};
	outs = {"Raw", "Roasted", "Boiled", "Ground", "Steeped", "Blanched", "Dried"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 40
	name = "10b: Medicinal Properties For";
	ins = {"only"};
	lims = {{}};
	for(int i(0); i < 95; i++) {
		lims[0].push_back(i+1);
	};
	lims[0].push_back(100);
	outs = {"Abortifacient", "Acrid", "Adjuvant", "Alterative", "Analgesic", "Anaphrodisiac", "Anesthetic", "Anodyne", "Anthelmintic", "Antibiotic", "Anticoagulant", "Antiemetic", "Antifungal", "Antihydrotic", "Antilithic", "Antinauseant", "Antiperodic", "Antiphlogistic", "Antipyretic", "Antiscorbutic", "Antiscrufulous", "Antiseptic", "Antispasmodic", "Antitussive", "Aperient", "Aphrodesiac", "Appetizer", "Aromatic", "Astringent", "Balsam", "Bitter", "Bitter Tonic", "Calmative", "Cardiac", "Carminative", "Cathartic", "Caustic", "Cholagouge", "Coagulant", "Colorant", "Counterirritant", "Demulcent", "Deodorant", "Depressant", "Depurative", "Detergent", "Diaphoretic", "Digestive", "Disinfectant", "Diuretic", "Dye", "Emmenagogue", "Emetic", "Emollient", "Errihine", "Euphoriant", "Expectorant", "Febrifuge", "Fungicide", "Galactagogue", "Glue", "Hallucinogen", "Haemostatic", "Hepatic", "Hydragogue", "Hypnotic", "Insecticide", "Irritant", "Laxative", "Mucilaginous", "Narcotic", "Nauseant", "Nephretic", "Nervine", "Oil", "Oxytocic", "Pectoral", "Poison", "Purgative", "Refridgerant", "Restorative", "Rubefacient", "Sedative", "Sialagogue", "Soporific", "Specific", "Stimulant", "Stomachic", "Vasodialator", "Vermicide", "Vermifuge", "Vesicant", "Vulnerary", "Wax", "Mysical / Other", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// elem 41
	name = "10c: Medicinal Preparation For";
	ins = {"only"};
	lims = {{5, 10, 15, 20, 25, 28, 35, 38, 45, 51, 55, 60, 65, 73, 76, 80, 85, 89, 93, 95, 98, 100}};
	outs = {"Bath", "Cold Compress", "Cold Extract", "Crushed", "Decoction", "Essence", "Fomentation", "Grated", "Ground", "Infusion", "Juice", "Ointment", "Poultice", "Powder", "Rubbed", "Syrup", "Tincture", "Vapor / Smoke", "Wash", "Whole", "Other", "Re-Roll"};
	FloraTabs.push_back( Table(name, ins, lims, outs) );

	// Fauna Tables
	//-------------------------------------------------------------------------------------------------------------------------------------------

	// elem 0
	name = "1: Skeleton";
	ins = {"only"};
	lims = {{80, 95, 100}};
	outs = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 1
	name = "2: Temp. Reg.";
	ins = {"only"};
	lims = {{45, 100}};
	outs = {"Warm Blooded", "Cold Blooded"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 2
	name = "3: Habitat";
	ins = {"Warm Blooded", "Cold Blooded"};
	lims = {{20, 35, 79, 100}, {40, 50, 89, 100}};
	outs = {"Aquatic", "Subterranean", "Terrestrial", "Avian"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 3
	name = "3a: Aquatic Sub-Habitat";
	ins = {"only"};
	lims = {{40, 80, 100}};
	outs = {"Salt Water", "Fresh Water", "Brackish"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 4
	name = "3b: Other Sub-Habitat";
	ins = {"only"};
	lims = {{10, 32, 37, 60, 75, 85, 100}};
	outs = {"Desert / Waste", "Plains / Savannah", "Swamp / Bog / Marsh", "Forest / Jungle", "Hills / Scrub", "Mountains", "Tundra"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 5
	name = "4: Diet";
	ins = {"only"};
	lims = {{30, 40, 80, 95, 97, 100}};
	outs = {"Carnivore", "Omnivore", "Herbivore", "Scavenger", "Parasite", "Symbiotic"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 6
	name = "4a: Social Type";
	ins = {"Carnivore", "Omnivore", "Herbivore", "Parasite", "Symbiotic"};
	lims = {{40, 80, 95, 99, 100},
			{30, 75, 90, 99, 100},
			{10, 40, 75, 98, 100},
			{30, 85, 89, 97, 100},
			{50, 85, 98, 99, 100}};
	outs = {"Solitary (1-2)", "Small Group (1-12)", "Medium Group (6-24)", "Large Group (20-80)", "Huge Group (80+)"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 7
	name = "4b: Temperament";
	ins = {"Carnivore", "Omnivore", "Herbivore", "Parasite", "Symbiotic"};
	lims = {{15, 70, 80, 97, 99, 100},
			{5, 30, 70, 90, 98, 100},
			{2, 8, 30, 50, 95, 100},
			{1, 10, 12, 15, 40, 100},
			{5, 30, 55, 70, 95, 100}};
	outs = {"Hostile", "Aggressive", "Friendly", "Wary", "Skittish", "Oblivious"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 8
	name = "4c: Territoriality";
	ins = {"Solitary (1-2)", "Small Group (1-12)", "Medium Group (6-24)", "Large Group (20-80)", "Huge Group (80+)"};
	lims = {{15, 30, 60, 100},
			{35, 50, 75, 100},
			{25, 50, 75, 100},
			{10, 35, 80, 100},
			{5, 60, 95, 100}};
	outs = {"Nomadic", "Migratory", "Range", "Hive / Den / Nest"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 9
	name = "5: Mass (Kg)";
	ins = {"Endoskeleton Warm Blooded", "Exoskeleton Warm Blooded", "Muscoskeleton Warm Blooded", "Endoskeleton Cold Blooded", "Exoskeleton Cold Blooded", "Muscoskeleton Cold Blooded"};
	lims = {{5, 20, 70, 95, 98, 100},
			{3, 25, 45, 70, 90, 100},
			{1, 10, 55, 75, 95, 100},
			{3, 15, 55, 85, 98, 100},
			{2, 15, 30, 50, 80, 100},
			{1, 20, 50, 70, 90, 100}};
	outs = {"Huge (>1000)", "Large (100-1000)", "Avg. (10-100)", "Small (0.1-10)", "Tiny (0.001-0.1)", "Minuscule (<0.001)"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 10
	name = "5a: Symmetry";
	ins = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	lims = {{97, 99, 100},
			{80, 95, 100},
			{20, 40, 100}};
	outs = {"Linear", "Radial", "Torsional"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 11
	name = "5b: Frame";
	ins = {"Carnivore", "Omnivore", "Herbivore"};
	lims = {{10, 50, 80, 95, 100},
			{10, 30, 70, 90, 100},
			{5, 20, 55, 90, 100}};
	outs = {"Scant", "Light", "Average", "Heavy", "Massive"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 12
	name = "5c: Shape";
	ins = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	lims = {{10, 25, 90, 99, 100},
			{15, 45, 85, 95, 100},
			{20, 40, 60, 80, 100}};
	outs = {"Tubular", "Flat", "Ovoid", "Spherical", "Amorphous"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 13
	name = "6: Neck Length (% Body Length)";
	ins = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	lims = {{1, 3, 30, 90, 100},
			{20, 94, 97, 99, 100},
			{87, 97, 98, 99, 100}};
	outs = {"None", "Tiny (<10%)", "Short (10-25%)", "Medium (25-75%)", "Long (75-150%)"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 14
	name = "6a: Eyes";
	ins = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	lims = {{1, 2, 50, 99, 100},
			{5, 65, 75, 90, 100},
			{10, 40, 60, 98, 100}};
	outs = {"None", "Stalked", "Forward", "Sides", "Extra Pair"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 15
	name = "7: Limb Count";
	ins = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	lims = {{8, 14, 95, 99, 100},
			{5, 60, 85, 95, 100},
			{40, 60, 80, 90, 100}};
	outs = {"0 Limbs", "2 Limbs", "4 Limbs", "6 Limbs", "Re-Roll"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 16
	name = "7a: Tail/s";
	ins = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	lims = {{5, 90, 99, 100},
			{5, 15, 99, 100},
			{10, 30, 98, 100}};
	outs = {"Appendage", "Tail", "No-Tail", "Re-Roll"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 17
	name = "7b: Flight";
	ins = {"only"};
	lims = {{45, 50, 95, 100}};
	outs = {"Powered Wings / No Appendages", "Powered Wings / Appendages", "Glider", "Parachute / Balloon / Drifter"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 18
	name = "7c: Swimming";
	ins = {"only"};
	lims = {{30, 80, 85, 95, 100}};
	outs = {"Webbing", "Fins / No Appendages", "Fins / Appendages", "Jet / Body-Twisting / Drifter", "Doesn't Swim"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 19
	name = "7d: Limb Length (% Body Length)";
	ins = {"Carnivore", "Omnivore", "Herbivore"};
	lims = {{1, 15, 35, 60, 100},
			{1, 25, 50, 75, 100},
			{1, 20, 60, 85, 100}};
	outs = {"Vestigial (1-5%)", "Stubby (5-25%)", "Short (25-50%)", "Medium (50-100%)", "Long (100-150%)"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 20
	name = "7e: Appendages";
	ins = {"Endoskeleton Carnivore", "Endoskeleton Omnivore", "Endoskeleton Herbivore", "Exoskeleton Carnivore", "Exoskeleton Omnivore", "Exoskeleton Herbivore", "Muscoskeleton Carnivore", "Muscoskeleton Omnivore", "Muscoskeleton Herbivore"};
	lims = {{10, 15, 96, 99, 100},
			{30, 40, 95, 99, 100},
			{60, 65, 97, 99, 100},
			{30, 96, 97, 98, 100},
			{40, 96, 97, 98, 100},
			{70, 96, 97, 98, 100},
			{3, 12, 20, 94, 100},
			{2, 10, 20, 95, 100},
			{1, 5, 10, 96, 100}};
	outs = {"Hoof", "Pincer", "Paw", "Prehensile", "Other?"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 21
	name = "8: Skin";
	ins = {"Endoskeleton Warm Blooded", "Endoskeleton Cold Blooded", "Exoskeleton Warm Blooded", "Exoskeleton Cold Blooded", "Muscoskeleton Warm Blooded", "Muscoskeleton Cold Blooded"};
	lims = {{35, 40, 90, 97, 98, 100},
			{40, 85, 90, 95, 98, 100},
			{40, 50, 90, 98, 98, 100},
			{55, 65, 95, 98, 98, 100},
			{65, 70, 85, 90, 98, 100},
			{70, 75, 80, 80, 98, 100}};
	outs = {"Smooth / Slick", "Scaly / Pebbled", "Hairy / Furry", "Feathery", "Shelled", "Re-Roll"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 22
	name = "8a: Skin Color";
	ins = {"Smooth / Slick", "Scaly / Pebbled", "Hairy / Furry", "Feathery", "Shelled"};
	lims = {{10, 23, 28, 38, 46, 54, 64, 80, 89, 94, 100},
			{8, 16, 24, 34, 50, 56, 65, 78, 89, 95, 100},
			{12, 24, 30, 50, 56, 70, 80, 85, 92, 96, 100},
			{11, 26, 33, 40, 50, 60, 70, 80, 89, 95, 100},
			{10, 20, 25, 31, 39, 47, 57, 67, 87, 97, 100}};
	outs = {"Black", "Grey", "White", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Re-Roll"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 23
	name = "8b: Multicolor Transition";
	ins = {"2", "3", "4", "5", "6", "7", "8"};
	lims = {{20, 40, 60, 74, 81, 87, 89, 96, 100},
			{25, 45, 60, 75, 82, 85, 86, 95, 100},
			{30, 45, 60, 74, 81, 83, 84, 94, 100},
			{30, 45, 60, 74, 81, 83, 84, 94, 100},
			{30, 45, 60, 74, 81, 83, 84, 94, 100},
			{30, 45, 60, 74, 81, 83, 84, 94, 100},
			{30, 45, 60, 74, 81, 83, 84, 94, 100}};
	outs = {"Mottled", "Spots", "Stripes", "Patches", "Ornate", "Iridescent", "Florescent", "Phasing", "Mixed"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 24
	name = "9: 1st Attack / Defense";
	ins = {"Carnivore", "Omnivore", "Herbivore"};
	lims = {{100, 100, 100, 100, 100},
			{0, 100, 100, 100, 100},
			{0, 0, 33, 66, 100}};
	outs = {"Bite", "None", "Claw / Kick", "Leaping", "Speed"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 25
	name = "9a: 2nd Attack / Defense";
	ins = {"Endoskeleton", "Exoskeleton", "Muscoskeleton"};
	lims = {{10, 20, 30, 40, 50, 59, 60, 61, 72, 73, 78, 79, 99, 100},
			{20, 25, 32, 39, 48, 55, 57, 58, 65, 73, 83, 84, 99, 100},
			{7, 14, 18, 28, 38, 39, 41, 55, 60, 75, 78, 79, 99, 100}};
	outs = {"Bite / Tusks", "Camouflage", "Claw / Kick", "Club / Crush", "Horns / Spines", "Climbing / Leaping", "Proboscis", "Slime / Spray", "Speed", "Poison / Venom", "Armor", "Other", "None", "Re-Roll"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 26
	name = "10: Intelligence";
	ins = {"Carnivore Warm Blooded", "Omnivore Warm Blooded", "Herbivore Warm Blooded", "Carnivore Cold Blooded", "Omnivore Cold Blooded", "Herbivore Cold Blooded"};
	lims = {{5, 6, 75, 99, 100},
			{10, 11, 70, 98, 100},
			{25, 26, 79, 99, 100},
			{20, 22, 84, 98, 100},
			{30, 33, 79, 99, 100},
			{40, 42, 74, 99, 100}};
	outs = {"Instinctual", "Hive Mind", "Animal", "Cunning Animal", "Sapient"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 27
	name = "10a: Intelligence";
	ins = {"Carnivore", "Omnivore", "Herbivore"};
	lims = {{50, 80, 99, 100},
			{40, 70, 99, 100},
			{30, 60, 99, 100}};
	outs = {"Instinctual", "Animal", "Cunning Animal", "Sapient"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 28
	name = "11: Reproduction";
	ins = {"Warm Blooded", "Cold Blooded"};
	lims = {{70, 77, 96, 98, 100},
			{10, 60, 90, 98, 100}};
	outs = {"Live Birth", "Eggs", "Brood Eggs", "Larvae", "Re-Roll"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// elem 29
	name = "11b: Sexual Type";
	ins = {"only"};
	lims = {{70, 89, 95, 100}};
	outs = {"Two Sexes", "Hermaphrodite", "Asexual", "Re-Roll"};
	FaunaTabs.push_back( Table(name, ins, lims, outs) );

	// End of Tables
	//-------------------------------------------------------------------------------------------------------------------------------------------
}
TablesManager::~TablesManager() {
}
vector<string> TablesManager::MakePlant() {
	vector<string> tmp_str_vec;
	vector<string> out = {};
	string oly = "only";
	string temp;
	FloraNams = {};
	int temp_i;
	int temp_i2;

	// elem 0
	out.push_back( FloraTabs[0].getElem( oly, Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[0].getNam() );

	// elem 1
	out.push_back( FloraTabs[1].getElem( out[0], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[0].getNam() );

	// elem 2
	if(out.back() == "Aquatic") {
		out.push_back( FloraTabs[2].getElem( oly, Roll(1, 100) ) );
	} else {
		out.push_back( FloraTabs[3].getElem( oly, Roll(1, 100) ) );
	};
	FloraNams.push_back( FloraTabs[2].getNam() + " or " + FloraTabs[3].getNam() );

	if(out.back().find("Re-Roll") != string::npos || out.back().find("Tundra") != string::npos) {
		out.back() = FloraTabs[3].getElem( oly, Roll(6, 100) ) + " & " + FloraTabs[3].getElem( oly, Roll(6, 100) );
	};
	// elem 3
	out.push_back( FloraTabs[4].getElem( oly, Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[4].getNam() );

	// elem 4
	out.push_back( FloraTabs[5].getElem( out[0], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[5].getNam() );

	// elem 5
	out.push_back( FloraTabs[6].getElem( out[0], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[6].getNam() );

	// elem 6
	out.push_back( FloraTabs[7].getElem( out[0], Roll(1, 100) ) );

	while( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[7].getElem( out[0], Roll(1, 100) ) + " & " + FloraTabs[7].getElem( out[0], Roll(1, 100) );
	};
	FloraNams.push_back( FloraTabs[7].getNam() );

	// elem 7
	out.push_back( FloraTabs[8].getElem( out[0], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[8].getNam() );

	// elem 8
	out.push_back( FloraTabs[9].getElem( out[0], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[9].getNam() );

	for(int i(0); i < 3; i++) {
		string temp_nam;
		if(i == 0) {
			temp_nam = " Main Body";
		} else if(i == 1) {
			temp_nam = " Branches";
		} else if(i == 2) {
			temp_nam = " Roots";
		} else temp_nam = "";

		//elem 9 - 17
		tmp_str_vec = ColorsOf(out[0], temp_nam);
		out.insert( out.end(),  tmp_str_vec.begin(), tmp_str_vec.end() );
	};
	// elem 18
	out.push_back( FloraTabs[13].getElem( out[0], Roll(1, 100) ) );

	while( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[13].getElem( out[0], Roll(1, 100) ) + " & " + FloraTabs[13].getElem( out[0], Roll(1, 100) );
	};
	FloraNams.push_back( FloraTabs[13].getNam() );

	// elem 19
	if(out[0].find("Fungus") == string::npos) {
		out.push_back( FloraTabs[14].getElem( oly, Roll(1, 100) ) );

		if( out.back().find("Re-Roll") != string::npos ) {
			out.back() = FloraTabs[14].getElem( oly, Roll(1, 98) ) + " & " + FloraTabs[14].getElem( oly, Roll(1, 98) );
		};
	} else out.push_back("Terminal");
	FloraNams.push_back( FloraTabs[14].getNam() );

	// elem 20
	out.push_back( FloraTabs[15].getElem( oly, Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[15].getElem( oly, Roll(1, 98) ) + " & " + FloraTabs[15].getElem( oly, Roll(1, 98) );
	};
	FloraNams.push_back( FloraTabs[15].getNam() );

	// elem 21
	out.push_back( FloraTabs[16].getElem( oly, Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[16].getElem( oly, Roll(1, 95) ) + " & " + FloraTabs[16].getElem( oly, Roll(1, 95) );
	};
	FloraNams.push_back( FloraTabs[16].getNam() );

	// elem 22
	out.push_back( FloraTabs[17].getElem( oly, Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[17].getElem( oly, Roll(1, 96) ) + " & " + FloraTabs[17].getElem( oly, Roll(1, 96) );
	};
	FloraNams.push_back( FloraTabs[17].getNam() );

	// elem 23
	out.push_back( FloraTabs[18].getElem( oly, Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[18].getElem( oly, Roll(1, 99) ) + " & " + FloraTabs[18].getElem( oly, Roll(1, 99) );
	};
	FloraNams.push_back( FloraTabs[18].getNam() );

	// elem 24
	out.push_back( FloraTabs[19].getElem( oly, Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[19].getElem( oly, Roll(1, 95) ) + " & " + FloraTabs[19].getElem( oly, Roll(1, 95) );
	};
	FloraNams.push_back( FloraTabs[19].getNam() );

	// elem 25 - 26
	tmp_str_vec = ColorsOf(out[0], " Leaves");
	out.insert( out.end(), tmp_str_vec.begin(), tmp_str_vec.end() );

	// elem 27
	out.push_back( FloraTabs[20].getElem( out[0], Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[20].getElem( out[0], Roll(1, 99) ) + " & " + FloraTabs[20].getElem( out[0], Roll(1, 99) );
	};
	FloraNams.push_back( FloraTabs[20].getNam() );

	// elem 29
	out.push_back( FloraTabs[21].getElem( out[0], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[21].getNam() );

	// elem 30
	out.push_back( FloraTabs[22].getElem( out.back(), Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[22].getNam() );

	// elem 31
	out.push_back( FloraTabs[23].getElem( out[out.size()-2], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[23].getNam() );

	// elem 32
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[24].getElem( out.back(), Roll(1, 100) ) );
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[24].getNam() );

	// elem 33
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[25].getElem( oly, Roll(1, 100) ) );
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[25].getNam() );

	// elem 34
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[26].getElem( oly, Roll(1, 100) ) );

		if( out.back().find("Re-Roll") != string::npos ) {
			out.back() = FloraTabs[26].getElem( oly, Roll(1, 90) ) + " & " + FloraTabs[26].getElem( oly, Roll(1, 90) );
		};
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[26].getNam() );

	// elem 35
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[27].getElem( oly, Roll(1, 100) ) );

		if( out.back().find("Re-Roll") != string::npos ) {
			out.back() = FloraTabs[27].getElem( oly, Roll(1, 96) ) + " & " + FloraTabs[27].getElem( oly, Roll(1, 96) );
		};
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[27].getNam() );

	// elem 36
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[28].getElem( oly, Roll(1, 100) ) );

		if( out.back().find("Re-Roll") != string::npos ) {
			out.back() = FloraTabs[28].getElem( oly, Roll(1, 98) ) + " & " + FloraTabs[28].getElem( oly, Roll(1, 98) );
		};
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[28].getNam() );

	// elem 37
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[29].getElem( oly, Roll(1, 100) ) );
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[29].getNam() );

	// elem 38
	temp_i = 0;
	if(out[0] == "Woody") temp_i = 15;

	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[30].getElem( oly, Roll(1 + temp_i, 100) ) );
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[30].getNam() );

	//elem 39
	if(out[31].find("None") == string::npos) {
		tmp_str_vec = ColorsOf(out[0], " Flowers");
	} else {
		tmp_str_vec = {"N/A", "N/A"};
		FloraNams.push_back( FloraTabs[11].getNam() );
		FloraNams.push_back( FloraTabs[12].getNam() );
	};
	out.insert(out.end(), tmp_str_vec.begin(), tmp_str_vec.end() );

	// elem 40
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[31].getElem( oly, Roll(1, 100) ) );

		if( out.back().find("Re-Roll") != string::npos ) {
			out.back() = FloraTabs[31].getElem( oly, Roll(1, 95) ) + " & " + FloraTabs[31].getElem( oly, Roll(1, 95) );
		};
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[31].getNam() );

	// elem 41
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[32].getElem( oly, Roll(1, 100) ) );
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[32].getNam() );

	// elem 42
	if(out[31].find("None") == string::npos) {
		out.push_back( FloraTabs[33].getElem( oly, Roll(1, 100) ) );
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[33].getNam() );

	// elem 43
	out.push_back( FloraTabs[34].getElem( out[0], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[34].getNam() );

	// elem 44
	out.push_back( FloraTabs[35].getElem( out[0], Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[35].getElem( out[0], Roll(1, 99) ) + " & " + FloraTabs[35].getElem( out[0], Roll(1, 99) );
	};
	FloraNams.push_back( FloraTabs[35].getNam() );

	// elem 45
	out.push_back( FloraTabs[36].getElem( out[out.size() - 2], Roll(1, 100) ) );
	FloraNams.push_back( FloraTabs[36].getNam() );

	// elem 46
	if(out.back() == "Sentient") {
		out.push_back( FloraTabs[37].getElem( oly, Roll(1, 100) ) );

		if( out.back().find("Hive") != string::npos ) {
			temp_i = Roll(1, 100);
			while(temp_i > 75 && temp_i <= 79) temp_i = Roll(1, 100);
			out.back() = "Hive & " + FloraTabs[37].getElem( oly, temp_i );
		};
	} else out.push_back("N/A");
	FloraNams.push_back( FloraTabs[37].getNam() );

	for(int i(0); i < 6; i++) {
		temp_i = 1;

		if(i == 0) {
			temp = " Leaves";
			if(out[18].find("None") == string::npos) {
				temp_i = 1;
			} else temp_i = 0;
		} else if(i == 1) {
			temp = " Flowers";
			if(out[31].find("None") == string::npos) {
				temp_i = 1;
			} else temp_i = 0;
		} else if(i == 2) {
			temp = " Fruit";
			if(out[29].find("Fruit") != string::npos) {
				temp_i = 1;
			} else temp_i = 0;
		} else if(i == 3) {
			temp = " Bark";
			if(out[0] == "Woody" && out[5] == "Average (25cm-1m)" || out[5] == "Large (1-10m)" || out[5] == "Huge (>10m)") {
				temp_i = 1;
			} else temp_i = 0;
		} else if(i == 4) {
			temp = " Stems";
			temp_i = 1;
		} else if(i == 5) {
			temp = " Roots";
			temp_i = 1;
		};
		// elem 47
		if(temp_i == 1) {
			out.push_back( FloraTabs[38].getElem( out[0], Roll(1, 100) ) );

			if( out.back().find("Re-Roll") != string::npos ) {
				out.back() = FloraTabs[38].getElem( out[0], Roll(1, 99) ) + " & " + FloraTabs[38].getElem( out[0], Roll(1, 99) );
			};
		} else out.push_back("N/A");
		FloraNams.push_back( FloraTabs[38].getNam() + temp );

		// elem 48 & 49
		if(out.back() == "Edible" || out.back() == "Nutritious / Tasty" && temp_i == 1) {
			out.push_back( FloraTabs[39].getElem( out.back(), Roll(1, 100) ) );
			out.push_back( "N/A" );
		} else if(out.back() == "Medicinal / Other" && temp_i == 1) {
			out.push_back( FloraTabs[41].getElem( oly, Roll(1, 100) ) );
			out.push_back( FloraTabs[40].getElem( oly, Roll(1, 100) ) );
		} else {
			out.push_back("N/A");
			out.push_back("N/A");
		};
		FloraNams.push_back( FloraTabs[39].getNam() + temp + " or " + FloraTabs[41].getNam() + temp);
		FloraNams.push_back( FloraTabs[40].getNam() + temp);
	};
	return out;
}
vector<string> TablesManager::MakeAnimal() {
	vector<string> strip_search;
	vector<string> out = {};
	string oly = "only";
	string temp;
	FaunaNams = {};
	int temp_i;
	int temp_i2;

	// elem 0
	out.push_back(FaunaTabs[0].getElem(oly, Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[0].getNam() );

	temp_i = 0;
	if(out.back() == "Exoskeleton") {
		temp_i = 30;
	} else if(out.back() == "Muscoskeleton") {
		temp_i = 20;
	};
	// elem 1
	out.push_back(FaunaTabs[1].getElem(oly, Roll(1+temp_i,100)));
	FaunaNams.push_back( FaunaTabs[1].getNam() );

	temp_i = 0;
	if(out[0] == "Exoskeleton") {
		temp_i = -10;
	} else if(out[0] == "Muscoskeleton") {
		temp_i = -20;
	};
	// elem 2
	out.push_back(FaunaTabs[2].getElem(out[1], Roll(1,100+temp_i)));
	FaunaNams.push_back( FaunaTabs[2].getNam() );

	if(out.back() == "Terrestrial" && out[0] == "Exoskeleton" && Roll(1, 100) <= 25) {
		out.back() = "Avian";
	};

	// elem 3 & 4
	if(out[2] == "Aquatic") {
		out.push_back(FaunaTabs[3].getElem(oly, Roll(1,100)));
	} else {
		temp_i = 0;
		if(out[1] == "Cold Blooded") temp_i = -10;
		out.push_back(FaunaTabs[4].getElem(oly, Roll(1, 100 + temp_i)));
		if(out.back() == "Tundra") {
			out.back() = FaunaTabs[4].getElem(oly, Roll(1, 100 + temp_i));
		};
	};
	FaunaNams.push_back( FaunaTabs[3].getNam() + " or " + FaunaTabs[4].getNam() );
	// elem 4
	out.push_back(FaunaTabs[5].getElem(oly, Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[5].getNam() );
	if(out.back() == "Scavenger") {
		out.back() = out.back() + " & " + FaunaTabs[5].getElem(oly, Roll(1, 60));
	} else if(out.back() == "Parasite" || out.back() == "Symbiotic") {
		out.back() = out.back() + " & " + FaunaTabs[5].getElem(oly, Roll(1, 80));
	};
	strip_search = {"Carnivore", "Omnivore", "Herbivore"};
	//elem 5
	out.push_back(FaunaTabs[6].getElem( StrStrip(strip_search, out[4]), Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[6].getNam() );
	//elem 6
	out.push_back(FaunaTabs[7].getElem( StrStrip(strip_search, out[4]), Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[7].getNam() );
	//elem 7
	out.push_back(FaunaTabs[8].getElem(out[5], Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[8].getNam() );
	//elem 8
	out.push_back(FaunaTabs[9].getElem(out[0] + " " + out[1], Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[9].getNam() );
	//elem 9
	out.push_back(FaunaTabs[10].getElem(out[0], Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[10].getNam() );
	//elem 10
	temp_i = 0;
	if(out[2] == "Avian") temp_i = -10;
	out.push_back(FaunaTabs[11].getElem( StrStrip(strip_search, out[4]), Roll(1, 100 + temp_i)));
	FaunaNams.push_back( FaunaTabs[11].getNam() );
	//elem 11
	temp_i = 0;
	temp_i2 = 0;
	if(out[0] == "Endoskeleton" || out[0] == "Exoskeleton") {
		if(out[10] == "Scant") {
			temp_i2 = -20;
		} else if(out[10] == "Light") {
			temp_i2 = -10;
		} else if(out[10] == "Large") {
			temp_i = 10;
		} else if(out[10] == "Massive") {
			temp_i = 20;
		};
	};
	out.push_back(FaunaTabs[12].getElem(out[0], Roll(1 + temp_i, 100 + temp_i2)));
	FaunaNams.push_back( FaunaTabs[12].getNam() );
	//elem 12
	out.push_back( to_string( BodyMassIndex(out[11], out[10]) ) );
	FaunaNams.push_back("Body Mass Index");
	//elem 13
	double t = pow( ( MassS2IMin(out[8])/stoi(out[12]) ), (1.0/3.0) );
	out.push_back( to_string(t) );
	FaunaNams.push_back("Torso Length Min. (m)");
	//elem 14
	t = pow( ( MassS2IMax(out[8])/stoi(out[12]) ), (1.0/3.0) );
	out.push_back( to_string(t) );
	FaunaNams.push_back("Torso Length Max. (m)");
	//elem 15
	out.push_back(FaunaTabs[13].getElem(out[0], Roll(1, 100)));
	FaunaNams.push_back( FaunaTabs[13].getNam() );
	//elem 16
	out.push_back(FaunaTabs[14].getElem(out[0], Roll(1, 100)));
	FaunaNams.push_back( FaunaTabs[14].getNam() );
	//elem 17
	out.push_back(FaunaTabs[15].getElem(out[0], Roll(1, 100)));
	FaunaNams.push_back( FaunaTabs[15].getNam() );
	while(out.back() == "Re-Roll") {
		out.back() = FaunaTabs[15].getElem( out[0], Roll(1, 100) );
	};
	//elem 18
	out.push_back(FaunaTabs[16].getElem(out[0], Roll(1, 100)));
	FaunaNams.push_back( FaunaTabs[16].getNam() );
	while(out.back() == "Re-Roll") {
		out.back() = FaunaTabs[16].getElem( out[0], Roll(1, 100) );
	};
	//elem 19
	if(out[2] == "Avian") {
		out.push_back(FaunaTabs[17].getElem(oly, Roll(1,100)));
	} else if(out[2] == "Aquatic") {
		out.push_back(FaunaTabs[18].getElem(oly, Roll(1,100)));
		if(out[0] == "Muscoskeleton") out.back() = "Jet / Body-Twisting / Drifter";
	} else {
		out.push_back("N/A");
	};
	FaunaNams.push_back( FaunaTabs[17].getNam() + " or " + FaunaTabs[18].getNam() );
	//elem 20
	out.push_back(FaunaTabs[19].getElem( StrStrip(strip_search, out[4]), Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[19].getNam() );
	if(out.back() == "Vestigial" && Roll(1, 100) <= 50) out.back() = "Internal Vestigial";

	//elem 21
	out.push_back(FaunaTabs[20].getElem(out[0] + " " + StrStrip(strip_search, out[4]), Roll(1,100)));
	FaunaNams.push_back( FaunaTabs[20].getNam() );
	//elem 22
	out.push_back(FaunaTabs[21].getElem(out[0] + " " + out[1], Roll(1,98)));
	FaunaNams.push_back( FaunaTabs[21].getNam() );
	//elem 23
	string tmp = out.back();
	out.push_back(FaunaTabs[22].getElem(tmp, Roll(1, 100)));
	FaunaNams.push_back( FaunaTabs[22].getNam() );
	int color_cnt(1);
	while(out.back().find("Re-Roll") != string::npos) {
		color_cnt++;
		out.back() = "";
		for(int i(0);i < color_cnt; i++) {
			out.back() = out.back() + " " + FaunaTabs[22].getElem(tmp, Roll(1, 100));
		};
	};
	//elem 24
	if(color_cnt > 1) {
		out.push_back(FaunaTabs[23].getElem(to_string(color_cnt), Roll(1, 100)));
	} else {
		out.push_back("N/A");
	};
	FaunaNams.push_back( FaunaTabs[23].getNam() );
	//elem 25
	out.push_back(FaunaTabs[24].getElem(StrStrip(strip_search, out[4]), Roll(1, 100)));
	FaunaNams.push_back( FaunaTabs[24].getNam() );
	//elem 26
	out.push_back(FaunaTabs[25].getElem(out[0], Roll(1, 99)));
	FaunaNams.push_back( FaunaTabs[25].getNam() );
	//elem 27
	out.push_back(FaunaTabs[26].getElem( StrStrip(strip_search, out[4]) + " " + out[1], Roll(1, 100)));
	FaunaNams.push_back( FaunaTabs[26].getNam() );
	if(out.back() == "Hive Mind") {
		out.back() = out.back() + " " + FaunaTabs[27].getElem( StrStrip(strip_search, out[4]), Roll(1, 100));
	};
	//elem 28
	out.push_back(FaunaTabs[28].getElem(out[1], Roll(1, 98)));
	FaunaNams.push_back( FaunaTabs[28].getNam() );
	//elem 29
	color_cnt = YoungCount( out.back() ) + YoungMod( out[8], StrStrip( strip_search, out[4] ) );
	if(color_cnt < 1) color_cnt = 1;
	out.push_back( to_string(color_cnt) );
	FaunaNams.push_back("11b: Youth Count");
	//elem 30
	out.push_back(FaunaTabs[29].getElem(oly, Roll(1, 95)));
	FaunaNams.push_back( FaunaTabs[29].getNam() );

	return out;
}
vector<string> TablesManager::getFloraNams() {
	return FloraNams;
}
vector<string> TablesManager::getFaunaNams() {
	return FaunaNams;
}
//Private
int TablesManager::Roll(int min, int max) {
	return ( rand() % (1+max-min) ) + min;
}
string TablesManager::StrStrip(vector<string> strippers, string stripee) {
	string out = "";

	for(int i(0); i < strippers.size(); i++) {
		if(stripee.find(strippers[i]) != string::npos) {
			out = strippers[i];
		};
	};
	return (out == "") ? "Error: No String Match" : out;
}
string TablesManager::PedalCount() {
	int r = Roll(1,100);

	if(r <= 10) {
		return "None";
	} else if(r <= 30) {
		return to_string( Roll(1,6) );
	} else if(r <= 60) {
		return to_string( Roll(1,4) + Roll(1,4) + Roll(1,4) );
	} else if(r <= 90) {
		return to_string( Roll(1,6) + Roll(1,6) + Roll(1,6) + Roll(1,6) );
	} else if(r <= 100) {
		return to_string( Roll(1,20) + Roll(1,20) + Roll(1,20) + Roll(1,20) + Roll(1,20) );
	} else return "None";
}
int TablesManager::YoungMod(string size, string diet) {
	if(size == "Huge (>1000)") {
		if(diet == "Carnivore") {
			return -50;
		} else if(diet == "Omnivore") {
			return -20;
		} else if(diet == "Herbivore") {
			return -55;
		};
	} else if(size == "Large (100-1000)") {
		if(diet == "Carnivore") {
			return -20;
		} else if(diet == "Omnivore") {
			return -10;
		} else if(diet == "Herbivore") {
			return -30;
		};
	} else if(size == "Avg. (10-100)") {
		if(diet == "Carnivore") {
			return 0;
		} else if(diet == "Omnivore") {
			return 10;
		} else if(diet == "Herbivore") {
			return 10;
		};
	} else if(size == "Small (0.1-10)") {
		if(diet == "Carnivore") {
			return 15;
		} else if(diet == "Omnivore") {
			return 20;
		} else if(diet == "Herbivore") {
			return 65;
		};
	} else if(size == "Tiny (0.001-0.1)") {
		if(diet == "Carnivore") {
			return -10;
		} else if(diet == "Omnivore") {
			return 10;
		} else if(diet == "Herbivore") {
			return 30;
		};
	} else if(size == "Minuscule (<0.001)") {
		if(diet == "Carnivore") {
			return 25;
		} else if(diet == "Omnivore") {
			return 15;
		} else if(diet == "Herbivore") {
			return 35;
		};
	};
	return 0;
}
int TablesManager::YoungCount(string rep) {
	int r = Roll(1, 100);

	if(r <= 25) {
		if(rep == "Live Birth") {
			return ( (Roll(1,2) ) );
		} else if(rep == "Eggs") {
			return ( (Roll(1,2) ) );
		} else if(rep == "Brood Eggs") {
			return ( (Roll(1,3) ) );
		};
	} else if(r <= 50) {
		if(rep == "Live Birth") {
			return ( (Roll(1,6) ) );
		} else if(rep == "Eggs") {
			r = 0;
			for(int i(0); i < 3; i++) {
				r += Roll(1,20);
			};
			return ( (r) );
		} else if(rep == "Brood Eggs") {
			r = 0;
			for(int i(0); i < 2; i++) {
				r += Roll(1,4);
			};
			return ( (r) );
		};
	} else if(r <= 75) {
		if(rep == "Live Birth") {
			r = 0;
			for(int i(0); i < 2; i++) {
				r += Roll(1,4);
			};
			return ( (r) );
		} else if(rep == "Eggs") {
			r = 0;
			for(int i(0); i < 2; i++) {
				r += Roll(1,4);
			};
			return ( (r * 25) );
		} else if(rep == "Brood Eggs") {
			r = 0;
			for(int i(0); i < 3; i++) {
				r += Roll(1,6);
			};
			return ( (r) );
		};
	} else if(r <= 100) {
		if(rep == "Live Birth") {
			r = 0;
			for(int i(0); i < 3; i++) {
				r += Roll(1,4);
			};
			return ( (r) );
		} else if(rep == "Eggs") {
			r = 0;
			for(int i(0); i < 2; i++) {
				r += Roll(1,6);
			};
			return ( (r * 100) );
		} else if(rep == "Brood Eggs") {
			r = 0;
			for(int i(0); i < 4; i++) {
				r += Roll(1,20);
			};
			return ( (r) );
		};
	};
}
int TablesManager::BodyMassIndex(string shape, string frame) {
	if(shape == "Tubular") {
		if(frame == "Scant") {
			return 3;
		} else if(frame == "Light") {
			return 4;
		} else if(frame == "Average") {
			return 5;
		} else if(frame == "Heavy") {
			return 6;
		} else if(frame == "Massive") {
			return 7;
		};
	} else if(shape == "Flat") {
		if(frame == "Scant") {
			return 6;
		} else if(frame == "Light") {
			return 8;
		} else if(frame == "Average") {
			return 10;
		} else if(frame == "Heavy") {
			return 12;
		} else if(frame == "Massive") {
			return 14;
		};
	} else if(shape == "Ovoid") {
		if(frame == "Scant") {
			return 12;
		} else if(frame == "Light") {
			return 16;
		} else if(frame == "Average") {
			return 20;
		} else if(frame == "Heavy") {
			return 24;
		} else if(frame == "Massive") {
			return 28;
		};
	} else if(shape == "Spherical" || shape == "Amorphous") {
		if(frame == "Scant") {
			return 24;
		} else if(frame == "Light") {
			return 32;
		} else if(frame == "Average") {
			return 40;
		} else if(frame == "Heavy") {
			return 48;
		} else if(frame == "Massive") {
			return 56;
		};
	};
}
float TablesManager::MassS2IMin(string in) {
	if(in == "Huge (>1000)") {
		return 1000.0;
	} else if(in == "Large (100-1000)") {
		return 100.0;
	} else if(in == "Avg. (10-100)") {
		return 10.0;
	} else if(in == "Small (0.1-10)") {
		return 0.1;
	} else if(in == "Tiny (0.001-0.1)") {
		return 0.001;
	} else if(in == "Minuscule (<0.001)") {
		return 0.0005;
	} else return 1.0;
}
float TablesManager::MassS2IMax(string in) {
	if(in == "Huge (>1000)") {
		return 2000.0;
	} else if(in == "Large (100-1000)") {
		return 1000.0;
	} else if(in == "Avg. (10-100)") {
		return 100.0;
	} else if(in == "Small (0.1-10)") {
		return 10.0;
	} else if(in == "Tiny (0.001-0.1)") {
		return 0.1;
	} else if(in == "Minuscule (<0.001)") {
		return 0.001;
	} else return 1.0;
}
vector<string> TablesManager::ColorsOf(string tab_ref,string temp_nam) {
	vector<string> out = {};

	if(temp_nam != " Leaves" || temp_nam != " Flowers") {
		out.push_back( FloraTabs[10].getElem( tab_ref, Roll(1, 100) ) );

		while( out.back().find("Re-Roll") != string::npos ) {
			out.back() = FloraTabs[10].getElem( tab_ref, Roll(1, 100) ) + " & " + FloraTabs[10].getElem( tab_ref, Roll(1, 100) );
		};
		FloraNams.push_back( FloraTabs[10].getNam() + temp_nam);
	};
	out.push_back( FloraTabs[11].getElem( "only", Roll(1, 100) ) );

	if( out.back().find("Re-Roll") != string::npos ) {
		out.back() = FloraTabs[11].getElem( "only", Roll(1, 95) ) + " & " + FloraTabs[11].getElem( "only", Roll(1, 95) );
	};
	FloraNams.push_back( FloraTabs[11].getNam() + temp_nam);

	if(temp_nam != " Flowers") {
		if(out.back().find("&") != string::npos) {
			out.push_back( FloraTabs[12].getElem( "only", Roll(1, 100) ) );

			if( out.back().find("Re-Roll") != string::npos ) {
			out.back() = FloraTabs[12].getElem( "only", Roll(1, 95) ) + " & " + FloraTabs[12].getElem( "only", Roll(1, 95) );
			};
		} else out.push_back("N/A");
		FloraNams.push_back( FloraTabs[12].getNam() + temp_nam);
	};
	return out;
}
#endif
