/*
 * Sifteo StoredObject Exampe
 * Details Here: https://developers.sifteo.com/docs/SifteoSDK/1.0.0/class_sifteo_1_1_stored_object.html#a42b814d79fdd03a479dc0ff4b0d47dba
 */

#include <sifteo.h>
#include "assets.gen.h"
using namespace Sifteo;

static const unsigned gNumCubes = 1;

static AssetSlot MainSlot = AssetSlot::allocate()
    .bootstrap(GameAssets);

static Metadata M = Metadata()
    .title("Stored Object Example")
    .package("com.sifteo.sdk.StoredObject", "1.0")
    .icon(Icon)
    .cubeRange(gNumCubes);

/*
This code example will store two values in stored objects the first time the progam is run. 
Once you quit and restart the program, it will then retreive the values and print them back out.
*/

void main()
{
    StoredObject saveDataOne(188); 

    /*
    Ok so the above line creates a reference to a stored object location. 
    It gives us the ability to read and write save data to somewhere we can retrieve it.

    We do this with key value pairs. Think of a dictionary where words reference 
    defentitions. 

    Word => Defention
    Car => A four wheeled vehicle.
    Key => Value

    In this case we're creating a StoredObject with the key '188'
    */

    StoredObject saveDataTwo(187); //This is our second stored object. It's key is 187.

    int x = 1; //this is the value we'll store in breadcrumb
    int y = 10; //this is the value we'll store in breadcrumb

    if (saveDataOne.readObject(x) <= 0) {
        LOG("no save data - writing some\n");
        saveDataOne.writeObject(x); //Write the value '1' to saveDataOne (whose key is 188)
        saveDataTwo.writeObject(y); //Write the value '10' to saveDataTwo (whose key is 187)
        LOG("Save data written. Restart the app now.\nWarning, reinstalling the app will wipe this data\nUse the base to restart the app");
    } else {
        int x_prime = 0;
        int y_prime = 0;

        saveDataOne.readObject(x_prime); //read the data in saveDataOne and assign it to x_prime
        saveDataTwo.readObject(y_prime); //read the data in saveDataOne and assign it to y_prime
        LOG("saveDataOne = %i\n", x_prime);
        LOG("saveDataTwo = %i\n", y_prime);
    }

    while (1) {
        System::paint();
    }
    
}
