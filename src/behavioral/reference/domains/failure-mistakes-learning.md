# Failure, mistakes, and learning

**Parent:** [`README.md`](../README.md)

## What this probes

**Humility + learning loop**: owning mistakes (without dwelling), retros, and growth when you were not the expert. Dodging “failure” questions often **hurts more** than a narrow honest miss plus prevention—do not invent a production disaster.

## Example questions

| # | Question | Note |
| --- | --- | --- |
| 1 | Tell me about a time you were wrong. | One beat own, 80% fix/learn. |
| 2 | A mistake in production or near-production. | Blast radius + mitigation. |
| 3 | What failure taught you the most? | Specific habit change. |
| 4 | Tell me about a retrospective that changed how you work. | Action items you kept. |
| 5 | When did you miss an expectation? | Manager/peer expectation OK. |
| 6 | Describe a project that did not go as planned. | Still show agency. |
| 7 | Tell me about learning a new language or stack under pressure. | Go SDK / ramp stories. |
| 8 | When were you not the expert in the room? | How you added value anyway. |
| 9 | How do you handle being outside your comfort zone? | Process + story. |
| 10 | Tell me about feedback that was hard to hear. | What you did after. |
| 11 | Tell me about a near miss you caught before it became an incident. | Honest alternative to “hero failure.” |
| 12 | When did you underestimate complexity? | Narrow truth beats fake drama. |

## Aligned stories

**Primary (failure / learning, interview-safe):**

- [Load testing integration: blocked path, expectation reset, and discovery](../../work-experience/2021-amazon-fba.md#load-testing-integration-blocked-path-expectation-reset-and-discovery) — **2021 · Amazon FBA.** Blocker was **my knowledge gap** plus **thin docs** for our layout; I **mis-ordered actions** under uncertainty until I forced a discovery sequence; **manager + renegotiated “done”**, parallel delivery, **internal code/repo** found older config pattern; **after:** ordered next steps in writing, sibling-repo evidence, honest calendar vs. effort.

**Backup (deadline / capacity / “too much in flight”):**

- [Clojure SDK, calendar limits, and a mentoring handoff](../../work-experience/2022-orkes-sdk.md#clojure-sdk-calendar-limits-and-a-mentoring-handoff) — **~first year · Orkes.** Go deep work vs. **sixth language (Clojure)** where I was weaker; **parallel personal venture** broke time organization; **manager transparency** and **mentored handoff** to eager teammate completed work; **after:** cap parallel hard-learning lanes, clearer side-work boundaries (side business since exited).

**Technical ramp (same company, different prompt — “not the expert” without calendar arc):**

- [Unblocking enterprise adoption by delivering a Go SDK from scratch](../../work-experience/2022-orkes-sdk.md#unblocking-enterprise-adoption-by-delivering-a-go-sdk-from-scratch) — limited prior Go; phased plan, tests, customer feedback, scope discipline.

**Customer contract / semver (same company — breaking upgrades, process failure):**

- [Public API hygiene: assumed low adoption, fast cleanup, and upgrade pain](../../work-experience/2022-orkes-sdk.md#public-api-hygiene-assumed-low-adoption-fast-cleanup-and-upgrade-pain) — **Orkes.** Assumed **low adoption** while **cleaning repo** and pushing **release automation**; skipped **doc links + public-surface** review; **force-push / rebase** on shared history hurt **upgraders**; **after:** tests over **every public entry point**, **deprecate-then-remove**, release checklist for docs, **protected default / no rewrite** on customer-tracked branches.

**Also aligned (not primary failure shape):**

- [Reducing on-call noise through root-cause fixes](../../work-experience/2021-amazon-fba.md#reducing-on-call-noise-through-root-cause-fixes) — mitigation / recurring pain; **not** a classic “I broke prod” unless you truly own that arc
- [Accelerating onboarding in a large C++ codebase](../../work-experience/2019-beyond-hft.md#accelerating-onboarding-in-a-large-c-codebase) — learning / enabling others overlap; optional backup if you want an earlier-career “outside comfort zone” variant

## Interview framing (first 20–30 seconds)

**FBA / knowledge + docs:** “I was blocked by **what I did not know yet** and **documentation that did not cover our shape**—I bounced between actions until I forced an order of operations. I told my manager early, reset what ‘done’ meant, and eventually found the answer in **internal code**, not hallway answers.”

**Orkes / capacity:** “I had taken on **too much in parallel**—a sixth SDK in a language I was weak in plus a **side venture**—and my **calendar** became the bug. I went to my manager, proposed **handing execution to a teammate** I could mentor, and we shipped that way. Now I **cap parallel deep bets** and I am not running that side business anymore.”

**Orkes / public API + upgrades:** “I treated a repo like **low-traffic internal work**, skipped **doc and public-surface review**, and used **force-push / rebase** on the shared line—**real users** paid for it on **upgrade**. I owned the fallout, fixed the path forward, and now I treat **every export as semver**, with **tests per public function**, **deprecate before delete**, and **no history games** on defaults customers track.”

## What not to say (anti-patterns)

- Blaming the **platform or the tool** without owning **your discovery strategy and timeline communication**.
- Implying a **major customer outage** if the honest story is **blocked work / calendar slip / knowledge gap**—proportionality beats drama.
- **Skipping the manager / expectation** thread—interviewers hear “evasive” if you only describe technical hunting.
- Presenting **research time** as “nothing happened”; frame **signals sent**, **parallel delivery**, and **what each probe ruled out**.
- Describing a **mentored handoff** as **dumping** the problem—keep **accountability for outcome**, **why** capacity changed, and **what** you transferred.
- **Rewriting public git history** on a shared default as “just cleanup”—name it as a **judgment error** and pair with **protected branches + changelog + no force-push to consumer-tracked lines**.

## Gaps and detail drills

- **Weak spot if you only dodge:** use **FBA** for “mistake under blocker / bad assumptions,” **Orkes Clojure** for “missed self-management / deadline risk,” and **Orkes public API** for “**customer contract** / upgrade surprise”—each has **before / after** in the role file.
- **Drill (Go-only):** Go SDK story — what you did **not** know on day 1 and how you **de-risked** (tests, reviews, scope) without mixing in the calendar handoff unless asked.
- **Drill (semver):** public API story — what you **test** now per release and how you **deprecate** before removal.
