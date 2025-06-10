**EVTOL_Coding_Standards_DO178C.md**

This document defines the coding standards and guidance followed in the EVTOL simulation project to align with DO-178C objectives and Design Assurance Level B (DAL-B) compliance expectations.

---

### 1. Language Restrictions and Safety Subset
- The project uses **C++**, constrained to a **MISRA-C++-like safe subset**.
- **Disallowed features:**
  - Exceptions in production (airborne) code
  - Templates (unless fully instantiated and predictable)
  - Run-Time Type Information (RTTI) and dynamic_cast
  - Multiple inheritance
  - Recursion
- **Allowed in unit tests only:**
  - `try/catch` blocks for exception testing (host-only, not certified code)

---

### 2. Exception Policy
- **Airborne code must not use exceptions.**
- `try/catch` is only used in **unit tests** to assert behavior boundaries or fault conditions.
- Documented in SDP and Verification Plan that exception use is confined to host-based test harnesses.

---

### 3. Modularity and Function Complexity
- Every class follows **single-responsibility** design.
- Target: functions have **<10 branches** (cyclomatic complexity <10)
- Functions exceeding this are broken into helper routines.

---

### 4. Memory Management
- No dynamic allocation in airborne code (no `new`, `delete`, `malloc`, `free`)
- Static and stack-allocated containers only (`std::vector` with pre-allocated capacity OK)
- No global mutable state

---

### 5. Initialization and Variable Usage
- All variables are explicitly initialized
- No undefined or implicit behavior (verified via static analysis)

---

### 6. Error Handling Strategy
- Controlled error return values or fault injection mechanisms are used (no exception flow)
- Fault states are explicitly tracked using flags or enumerations (e.g., `faultActive`)

---

### 7. Traceability
- All methods are linked to test cases via `test_evtol_methods.cpp`
- Future goal: use RTM tooling to link HLR ⇔ LLR ⇔ Code ⇔ Test

---

### 8. Unit Testing Policies
- **DAL-B aligned**: All public methods are unit tested
- Unit tests include **decision and boundary coverage**
- Negative paths and fault handling are explicitly tested

---

### 9. Static Analysis
- For certification, **Polyspace Code Prover/LDRA** recommended:
  - Confirms absence of overflow, dead code, uninitialized variables, Run-Time Type Information (RTTI), unreachable code, infinite loops, race conditions/unexpected paths, etc.
  - Supports DO-330 qualification if needed

---

### 10. Naming and Style Conventions
- `PascalCase` for class names (e.g., `AlphaEVTOL`)
- `camelCase` for methods and variables (e.g., `simulateStep()`)
- Header guards or `#pragma once` in every `.hpp`
- Max 100 characters per line

---

### 11. Code Review Requirements
- Every change is peer-reviewed
- Checklists include: initialization, complexity, style, traceability, memory safety
- All issues are tracked via issue tracking tool (e.g., Jira)

---

### 12. Certification Position
- Code is DAL-B **test-rigorous**, **deterministic**, and modular
- Code does **not yet meet full DO-178C DAL-B** until:
  - Bidirectional traceability is established
  - Structural coverage (MC/DC) is gathered
  - Reviews are documented and baselines frozen

---

**Maintained by:** EVTOL Simulation Compliance Team (Christopher Britton) 
**Date:** 6/5/2025