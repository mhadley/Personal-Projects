# L4D2 tactical gunplay (working title)

A solo Left 4 Dead 2 mod, played from the player's own copy of the game, with the
feel of SCP: 5K (credited as inspiration only; no SCP: 5K files are used).

v0.1 plan: tuned rifle, SMG, shotgun and pistol; leaning; a stamina sprint (dropped
if VScript cannot change player speed); arm and weapon sway where the game allows.
Multiplayer with friends comes later, only if the solo build is stable.

The design lives in `sheets/` (one row per weapon, movement system, hook and
in-game test). Run `python3 tools/preflight.py` to list unfilled cells, broken
references and untested items before any build.
