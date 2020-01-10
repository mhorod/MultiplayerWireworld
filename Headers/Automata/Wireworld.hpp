#ifndef AUTOMATA_WIREWORLD_HPP
#define AUTOMATA_WIREWORLD_HPP

#include "Game/Automaton.hpp"
#include "Game/CellState.hpp"
#include "Game/Grid.hpp"
#include "Game/CellCoords.hpp"

namespace Automata
{
class WireworldState : public Game::CellState
{
    enum Type
    {
        NONE,
        EMPTY,
        HEAD,
        TAIL,
        COND
    };

public:
    Type type;
};

class Wireworld : public Game::Automaton
{
public:
    Wireworld(Game::Grid &);
    virtual void update() override;

private:
    WireworldState calculate_new_state(const Game::CellCoords &);
    WireworldState calculate_conductor_state(const Game::CellCoords &);
    Game::Grid &grid;
};
} // namespace Automata

#endif // AUTOMATA_WIREWORLD_HPP