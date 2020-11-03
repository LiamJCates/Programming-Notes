State machine diagrams are used to visually describe a system's behavior.

take a particular object, look at the different states that that object can be in, and define the transitions that occur. Whether those transitions come from outside stimulus requesting the state change or whether they come from just events that may occur and cause a state to change.


The key components of these diagrams include states and transitions. The sample state machine
provided in the following diagram is for a bank vault. The solid circle is the initial pseudo
state and indicates entry into the system. There are four states—Wait, Unlock, Enable, and
Vault.
In our bank vault example, the vault is enabled when two bank managers place their thumb
on a thumbprint scanner. The vault is unlocked, contingent on a successful thumbprint
scan, by entering the correct combination. When these conditions are met, the Vault state is
reached and the managers can enter it:

[import example png]
