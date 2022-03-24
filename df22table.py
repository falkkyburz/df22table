from scipy import signal
import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path


ORDER = 8
NAME = ["df22table_bessel", "df22table_cheby", "df22table_butter"]
PASSBAND_RIPPLE_DB = 2
NUM = 9
CORNER_FREQ = [(x + 1) / (NUM + 1) for x in range(NUM)]

# Generate filter SOS structure parameters
df22table_bessel = []
df22table_cheby = []
df22table_butter = []
for w_c in CORNER_FREQ:
    df22table_bessel.append(signal.bessel(ORDER, w_c, output="sos"))
    df22table_cheby.append(signal.cheby1(ORDER, PASSBAND_RIPPLE_DB, w_c, output="sos"))
    df22table_butter.append(signal.butter(ORDER, w_c, output="sos"))
# Fill into a single table
df22table = [df22table_bessel, df22table_cheby, df22table_butter]

# Write table to df22table.c file
with Path(f"df22table{ORDER}.c").open("w") as f:
    freq_str = f"const float df22table_freq[{len(CORNER_FREQ)}] = {{"
    for e in CORNER_FREQ:
        freq_str += f"{e:.12f}f,"
    freq_str = freq_str[:-1] + "};"
    print(freq_str, file=f)
    for flt_table, flt_name in zip(df22table, NAME):
        nfreq = len(CORNER_FREQ)
        nsos = len(flt_table[0])
        ncoef = len(flt_table[0][0])
        sos_str = f"const float {flt_name}[{nfreq}][{nsos}][{ncoef}] = {{\n"
        for freq in flt_table:
            sos_str += "{"
            for sos in freq:
                sos_str += "{"
                for e in sos:
                    sos_str += f"{e:.12f}f,"
                sos_str = sos_str[:-1] + "},"
            sos_str = sos_str[:-1] + "},\n"
        sos_str = sos_str[:-2] + "};"
        print(sos_str, file=f)

# Plot all filters
fig, ax = plt.subplots(2, 3, figsize=[20, 10])
ax_g = ax[::2][0]
ax_p = ax[1::2][0]
for flt_type, axg, axp, tit in zip(df22table, ax_g, ax_p, NAME):
    for sos in flt_type:
        w, h = signal.sosfreqz(sos)
        axg.plot(w / np.pi, 20 * np.log10(abs(h)), "b")
        angles = np.unwrap(np.angle(h))
        axp.plot(w / np.pi, angles, "g")
    axg.set_title(tit)
    axg.set_ylabel("Amplitude [dB]", color="b")
    axg.set_ylim(bottom=-40, top=2)
    axg.set_xlabel("Frequency [pu nyq.]")
    axg.grid()
    axp.set_ylabel("Angle [rad]", color="g")
    axp.set_xlabel("Frequency [pu nyq.]")
    axp.grid()

fig.tight_layout()

plt.show()
