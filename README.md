# Extended Sun RPC Calculator

An extended client-server RPC calculator in C implementing arithmetic, modulo, power, and square root operations.

## Available Operations

| Operation | Symbol | Server Procedure | Prototype / Types |
| :--- | :---: | :--- | :--- |
| **Addition** | `+` | `add_1_svc` | `float *add_1_svc(floatpair *, struct svc_req *)` |
| **Subtraction** | `-` | `sub_1_svc` | `float *sub_1_svc(floatpair *, struct svc_req *)` |
| **Multiplication**| `*` | `mul_1_svc` | `float *mul_1_svc(floatpair *, struct svc_req *)` |
| **Division** | `/` | `div_1_svc` | `float *div_1_svc(floatpair *, struct svc_req *)` |
| **Modulo** | `%` | `mod_1_svc` | `float *mod_1_svc(floatpair *, struct svc_req *)` (`fmod`) |
| **Power** | `^` | `puissance_1_svc` | `float *puissance_1_svc(floatpair *, struct svc_req *)` (`pow`) |
| **Square Root** | `r` | `racine_1_svc` | `float *racine_1_svc(floatsingle *, struct svc_req *)` (`sqrt`) |

---

## Prerequisites (Linux / WSL)

```bash
sudo apt update && sudo apt install -y build-essential rpcbind libtirpc-dev rpcsvc-proto
```

Make sure the RPC portmapper service is running:
```bash
sudo service rpcbind restart   # or: sudo systemctl enable --now rpcbind
```

---

## Compilation

You can compile using `make` directly:

```bash
make
```

Or manually using `gcc`:

```bash
# Compile Server
gcc -o calculator_server calculator_svc.c calculator_server.c calculator_xdr.c -I/usr/include/tirpc -ltirpc -lm

# Compile Client
gcc -o calculator_client calculator_clnt.c calculator_client.c calculator_xdr.c -I/usr/include/tirpc -ltirpc -lm
```

---

## Execution

1. **Terminal 1: Start Server**
   ```bash
   ./calculator_server
   ```

2. **Terminal 2: Run Client**
   ```bash
   ./calculator_client 127.0.0.1
   ```

3. **Sample Interactions:**
   - **Modulo**: Choose `%`, enter `10 3` -> `Result: 1.00`
   - **Power**: Choose `^`, enter `2 3` -> `Result: 8.00`
   - **Square Root**: Choose `r`, enter `25` -> `Result: 5.00`

"# RPC-CALC" 
