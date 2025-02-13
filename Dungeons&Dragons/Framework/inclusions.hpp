#include <iostream>
#include <vector>

// Standard inclusions most files would use.
using namespace std;

template <typename T>
class I_map {
    unordered_map<string, T> map;

    public:
        /**
         * @brief A get function to get a value from the map
         * @param key The string identifier of the value
         * @returns A copy of the value at the key position
         * @author BerlinVincent
         */
        T get(string key) {
            return map[key];
        }

        /**
         * @brief A set function to enter a value into the map
         * @param key The string identifier for the value
         * @param value The value to be inserted into the map
         * @author BerlinVincent
         */
        void set(string key, T value) {
            map[key] = value;
        }

        /**
         * @brief A get function to get the entire map
         * @returns A copy of the map
         * @author BerlinVincent
         */
        unordered_map<string, T> getMap() {
            return map;
        }
};