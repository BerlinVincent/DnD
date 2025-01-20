#ifndef STATE_H_
#define STATE_H_

#include "../pack.hpp"
namespace game {

  struct Action;
  class State : Pack, Unpack
  {
    // Player player;
    // scenes::Scene scene;
    // menu
    Action *action {};
  };
}

#endif // STATE_H_
