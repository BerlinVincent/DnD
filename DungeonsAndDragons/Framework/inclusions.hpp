#ifndef INCLUSIONS_H_
#define INCLUSIONS_H_

#include <iostream>
#include <vector>
#include <unordered_map>

// Standard inclusions most files would use.
using namespace std;

/**
 * @brief An Interface class for operations on a map<string, T>
 * @tparam T The Type of Element contained in the map
 */
template <typename T> class I_map {

private:
    unordered_map<string, T> map;
    
public:
    /**
     * @brief A get function to get a value from the map
     * @param key The string identifier of the value
     * @returns A copy of the value at the key position
     * @author BerlinVincent
     */
    auto get(string key) -> T {
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
    auto getMap() -> unordered_map<string, T> {
        return map;
    }

    I_map<T>() = default;
    I_map<T>(unordered_map<string, T> map) : map(map) {}
};

#endif // INCLUSIONS_H_