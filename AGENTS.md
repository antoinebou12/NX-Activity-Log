## Learned User Preferences

- Prefer integrating the maintained zdm65477730 fork / PR #76 for HOS compatibility over hand-porting minimal patches on the original tallbl0nde tree.
- Prefer shipping work to the user's fork `antoinebou12/NX-Activity-Log` on `main` (downloads, README, and in-app update URL should point there).
- When scoping fixes, prefer the simplest high-impact option; for incorrect playtime, attribute no-user (orphan) sessions to the currently viewed user rather than tackling All Activity freeze or applet OOM in the same pass unless asked.

## Learned Workspace Facts

- This repo is Nintendo Switch homebrew (NX Activity Log); `origin` is `antoinebou12/NX-Activity-Log`, `upstream` is `tallbl0nde/nx-activity-log`, and `zdm` is `zdm65477730/NX-Activity-Log`.
- Working branch for HOS 22 work has been `hos-22-pr76`, based on the zdm PR #76 tip with fork branding/update URL changes.
- HOS 22.x support means rebuilding with modern libnx (≥ 4.10; local DevKitPro has had libnx 4.12.0) under Atmosphere ≥ 1.11; primary deliverable is title-mode `.nro` (User Page/Album applet mode remains memory-constrained).
- Community HOS16–21 fixes (u64 timestamps, paginated PDM queries, ghost-record filters, loading progress UI) live in the zdm tree / PR #76 rather than upstream v1.4.0.
- Orphan play sessions (no `Account_Active`/`Account_Inactive`) should be matched in `PlayData::getPDSessions` so Recent Activity and Details attribute them to the viewed user; All Activity still uses PDM `getStatisticsForUser` totals.
