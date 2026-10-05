# Handoff: continue on the PC that has Left 4 Dead 2

Decisions made with the user
- Mashup: solo Left 4 Dead 2 gunplay overhaul with the feel of SCP: 5K (credited as inspiration only; no SCP: 5K files or assets).
- Required game: Left 4 Dead 2 only. SCP: 5K is not in Melty's catalog (can only be named as the related game `custom-scp-5k`).
- v0.1 scope: tuned weapons + lean + stamina sprint. If the sprint probe fails, ship lean + gunplay only. Arm/weapon sway is a must-have, as far as the game allows.
- Solo first; multiplayer with friends (own listen server, up to 4) only if solo is stable.

What Melty said (game_info / search_mashups)
- L4D2: engine source, no loader Melty installs, so only plain game files can be published (addon .vpk into `{game}/left4dead2/addons`). SourceMod is not an option.
- L4D2 is VAC-secured: keep to single-player, local servers and demos.
- Closest existing mashup: BlockDead 2 (blockdead-2), recipe = one zip with one .vpk mapped to `{game}/left4dead2/addons`, launch kind `game`, multiplayer maxPlayers 4. Copy that shape.
- No draft of ours exists yet on Melty (list_my_mods was empty).

Status
- `sheets/` and `tools/preflight.py` are in place; preflight is not clean (viewmodel_sway cells unfilled, everything unverified).
- Nothing is built, nothing is published.

Next, in this order (needs the game running)
1. Run probe p_weapon_override (ship a changed weapon_pistol.txt in a test addon, read it back in game).
2. Fill the weapon script key names from the game's own scripts into the sheet, then build the four tac_* overrides.
3. Run p_lean, then p_speed (sprint go/no-go), then p_viewmodel. Record each result in the probes sheet before building on it.
4. Re-run preflight until clean, build the addon, package as a zip, then inspect_package, validate_recipe and one_click_check.
5. Real gameplay screenshot of the lean or the tuned weapons, then listing, then test in Melty, then publish with the user's go-ahead.

The Melty token is not stored here. Ask the user for a fresh Publish prompt from Melty if the tools are not already connected.
