### Cryptographic hash function

A **cryptographic hash function** must meet strict security requirements to ensure data integrity, authentication, and resistance to attacks. Below are the preferable characteristics:

---

## **1. Deterministic**
- The same input **must always** produce the same hash value.
- Ensures reliability in verification and authentication processes.

## **2. Preimage Resistance (One-Way Property)**
- Given a hash value **H(x)**, it should be **computationally infeasible** to determine the original input **x**.
- Prevents attackers from retrieving the original message.

## **3. Second Preimage Resistance**
- Given an input **x**, it should be **difficult** to find another input **x'** such that **H(x) = H(x')**.
- Prevents an attacker from replacing data with another input that has the same hash.

## **4. Collision Resistance**
- It should be **extremely difficult** to find two distinct inputs **x** and **y** such that **H(x) = H(y)**.
- Prevents forgery and tampering attacks.

## **5. Avalanche Effect**
- A **small change** in the input should cause a **drastic change** in the hash output.
- Ensures that even minor modifications to data are easily detectable.

## **6. Fixed-Length Output**
- The hash function should always produce a **fixed-length** output, regardless of input size.
- Example: SHA-256 always produces a **256-bit** output.

## **7. Computational Efficiency**
- The function should be **fast** to compute, even for large inputs.
- Balances speed with security (e.g., SHA-3 is slower but more secure than MD5).

## **8. Resistance to Birthday Attacks**
- The hash function must have a **large enough output size** to prevent birthday paradox-based attacks.
- A **minimum of 256 bits** is recommended for modern cryptographic security.

## **9. Non-Reversible (Irreversibility)**
- Given **H(x)**, it should be impossible to recover **x**.
- Ensures secure password storage and digital signatures.

## **10. Resistance to Length Extension Attacks**
- Hash functions should be **resistant to length extension attacks**, where an attacker can construct **H(x || y)** from **H(x)**.
- Example: SHA-3 and BLAKE2 are secure against this; older algorithms like **SHA-1 and MD5 are vulnerable**.

## **11. Keyed Hashing Support (HMAC)**
- The function should support a **keyed hashing mechanism** for authentication (e.g., HMAC-SHA256).
- Used in message authentication codes (MACs) and digital signatures.

## **12. Salt and Pepper Support for Password Hashing**
- The function should allow additional randomness (**salt**) to be added to inputs.
- Prevents rainbow table attacks when storing hashed passwords.

## **13. Resistance to Side-Channel Attacks**
- Should not leak information via **timing attacks** or **power analysis**.
- Example: Constant-time implementations prevent timing-based exploits.

---

### **Summary Table**

| **Characteristic**             | **Purpose** |
|--------------------------------|------------|
| **Deterministic**              | Same input always gives the same hash |
| **Preimage Resistance**        | Impossible to reverse the hash |
| **Second Preimage Resistance** | Prevents input substitution attacks |
| **Collision Resistance**       | Prevents two inputs from having the same hash |
| **Avalanche Effect**           | Small changes drastically change the hash |
| **Fixed-Length Output**        | Ensures consistent hash size (e.g., 256 bits) |
| **Computational Efficiency**   | Fast to compute for practical use |
| **Resistance to Birthday Attacks** | Reduces probability of hash collisions |
| **Non-Reversible**             | Ensures security in cryptographic applications |
| **Length Extension Resistance** | Prevents attackers from appending data |
| **Supports HMAC**              | Enables secure authentication methods |
| **Salt & Pepper Compatibility** | Protects password hashing from attacks |
| **Side-Channel Attack Resistance** | Prevents timing and power analysis exploits |

---

### **Examples of Secure Cryptographic Hash Functions**
✅ **SHA-3 (Keccak)**  
✅ **SHA-256 (widely used for security)**  
✅ **BLAKE2 (optimized and secure)**  
✅ **Argon2 (best for password hashing)**  

🚫 **Insecure Hash Functions (Avoid These)**  
❌ **MD5** (collisions found)  
❌ **SHA-1** (vulnerable to attacks)  

---

### **Conclusion**
A strong cryptographic hash function must be **secure, resistant to attacks, and computationally efficient**. Modern applications use **SHA-256, SHA-3, and BLAKE2** for their reliability. 