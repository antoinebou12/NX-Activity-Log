# NX Activity Log

**NX Activity Log** is a homebrew application for the Nintendo Switch which displays more precise information about your play activity.

[Download](https://github.com/antoinebou12/NX-Activity-Log/releases)

Fork of [tallbl0nde/NX-Activity-Log](https://github.com/tallbl0nde/NX-Activity-Log) with continued maintenance. Incorporates [PR #76](https://github.com/tallbl0nde/NX-Activity-Log/pull/76) / [zdm65477730/NX-Activity-Log](https://github.com/zdm65477730/NX-Activity-Log) (HOS 16+ fixes through 21.x) and rebuilds against modern libnx for **HOS 22.0.5**.

### Firmware / CFW requirements

* **HOS 22.0.5 (and 22.x):** Atmosphere **≥ 1.11.0** (1.11.2 recommended for 22.5.0). Homebrew launch on 22.0.0+ relies on Atmosphere's `am` compatibility patches.
* **HOS 21.0.0+:** Rebuild with **libnx ≥ 4.10.0** (TLS ABI change). This release targets current libnx (4.11.x / latest).
* **Older firmwares:** The same binary is intended to run under current Atmosphere on earlier HOS versions; use title/hbmenu launch rather than User Page if the forwarder path fails.

Curious about what's next? See the original to-do list on [Trello](https://trello.com/b/HaJ1THGq/nx-activity-log)

## Contents

1. [Features](#features)
2. [Screenshots](#screenshots)
3. [Reporting Incorrect Data](#reporting-incorrect-data)
4. [Known Issues](#known-issues)
5. [Translations](#translations)
6. [Credits](#credits)
7. [Support](#support-3)

## Features

This application currently has the following features:

* Viewing Play Activity (per user)
  * All Time Activity
    * Total Playtime in minutes
    * Number of times a game has been launched
    * Date of first launch
    * Date/time of most recent launch
    * Average time spent in a game
    * Sorting games by time played, recently played, etc.
  * Recent Activity (see note below)
    * Graph visualizing play time
    * View by day, month or year
    * Total playtime in seconds
    * Number of launches
    * Viewing each 'Play Session'
  * Event-by-event breakdown of your activity
* Multi-language Support
  * English, Chinese (Simplified and Traditional), French, German, Italian, Korean, Portugese, Russian, Spanish, Japanese, Ukrainian and Turkish
* Theme Support
  * Automatic theme detection to match the Switch's colour scheme
  * Custom Themes
    * All colours used in the app can be adjusted
    * Set a custom background image
      * **Requires a PNG saved at /config/NX-Activity-Log/background.png**
* Update in-app
  * Checks for updates automatically and displays an icon if one is available
  * Update completely within the app
* User Page Replacement
  * Requires LayeredFS and Atmosphere 0.10.0+ (or build and copy the forwarder to your CFW-specific titles folder)
  * **Requires .nro to be at /switch/NX-Activity-Log/NX-Activity-Log.nro**
  * Currently unreliable on HOS 21+/22.x — use title/hbmenu launch if User Page override crashes (see Known Issues)

_Note: The data shown in Recent Activity and Details may be slightly inaccurate over larger periods of time (ie. off by a few minutes) but I will try to improve this over time. If activity is not being shown for earlier periods of time it is likely your switch has been reset at some point, which wipes the data used to calculate playtime in this way._

## Screenshots

![Recent View](/Images/sc_recent.jpg)
![All Activity View](/Images/sc_activity.jpg)
![Detailed View](/Images/sc_detailed.jpg)

## Backup, Import & Transfer

Use Settings → **Export** / **Import** to move play data between consoles (or keep a backup).

1. **Backup:** Settings → Export. Copy `/switch/NX-Activity-Log/export.json` off the SD card.
2. **Restore / combine:** Copy that file to the other Switch as `/switch/NX-Activity-Log/import.json`, then Settings → Import, and **restart the app**.
3. Users are matched by **username**. Imported play sessions feed Recent Activity and Details; imported All Activity summaries are merged with on-console PDM totals (larger playtime/launches win, so a same-console re-import does not double-count).
4. **Delete imported data** (Settings) removes `/switch/NX-Activity-Log/importedData.json` only — it does **not** wipe Nintendo’s system play log. Clearing system PDM requires NAND-level tools and is outside this app.
5. Export/import is **not** a full NAND clone via HacDiskMount / NxNandManager; use JSON for app-visible history, or migrate system saves separately if you need stock profile totals.

For automation or scripts, parse `export.json` (`users` → `titles` → `events` + `summary`).

## Reporting Incorrect Data

If you are seeing wildly incorrect values/believe the playtime shown is incorrect within Recent Activity or the Details screen, please do the following:

1. Download and run the .nro from [here](https://github.com/zdm65477730/PlayEventParser/releases)
2. Leave it run; if it appears to be frozen leave it for up to a minute!
3. Once it is done there should be a playlog.txt at the root of your SD card.
4. Create an issue with the following:
    * Screenshots of the incorrect data (make sure the date/time and playtime are visible!)
    * The playlog.txt acquired from the last steps

_Note: Stock All Activity values come from the Switch PDM API. After Export/Import, this fork also merges imported summaries so migrated totals can appear in All Activity and Details._

## Known Issues

* **User Page replacement** may be incompatible on newer firmware / Atmosphere builds. Prefer launching from the homebrew menu (title mode) or Album until a forwarder fix lands.
* Playtime can look wrong after a factory reset (event history wiped) and/or for games that do not require a user. This fork attributes no-user sessions to the currently viewed user for Recent Activity and Details; use Export/Import to restore older history when you have a backup.
* Having a lot of games logged can cause too much memory usage when launched via User Page/Album, leading to out of memory crashes and/or missing images/text.
  * If it impacts you, launch this app in title mode for now.
  * Hide Titles skips icons when more than 200 titles are listed to reduce crashes.
* Having a lot of games logged can cause a long pause when loading the 'All Activity' screen (improved in the PR #76 / fork sync, but large libraries may still be slow).

## Translations

If you'd like to translate the app or fix an issue with a translation, please make a pull request to this repository (or open an issue). Japanese and other languages ship in `Application/romfs/lang/`.

## Credits

I'd like to thank:

* [zdm65477730](https://github.com/zdm65477730) for continued HOS 16–21 maintenance merged via [PR #76](https://github.com/tallbl0nde/NX-Activity-Log/pull/76)
* AtlasNX for [SimpleIniParser](https://github.com/AtlasNX/SimpleIniParser)
  * Used to read/write the config file
* nlohmann for his [JSON library](https://github.com/nlohmann/json)
* Switchbrew for [nx-hbloader](https://github.com/switchbrew/nx-hbloader) and [libnx](https://github.com/switchbrew/libnx)
  * Adapted to override User Page with this app; rebuilds require libnx ≥ 4.10.0 for HOS 21+/22.x
* Anyone else involved with the development of homebrew tools and reverse engineering of the Switch!

## Support <3

There is absolutely no obligation, however if you have found this software useful you can support me on Ko-fi!

[![ko-fi](https://www.ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/J3J718RRQ)

Knowing my software is being used is enough to motivate me to continue work on it!
