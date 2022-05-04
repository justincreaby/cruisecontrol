import sys
import csv

import matplotlib.pyplot as plt
import numpy as np

def load_data(dataFile):
  print ('File: ', dataFile)

  filename = open(dataFile, 'r')
  file = csv.DictReader(filename)
  # print(file)
  # create empty lists
  time = []
  setpoint = []
  velocity = []
  pterm = []
  iterm = []
  dterm = []
  ffterm = []
  force = []
 
  # iterate over each row and append values to empty list
  for col in file:
    time.append(float(col['time']))
    setpoint.append(float(col['setpoint']))
    velocity.append(float(col['velocity']))
    pterm.append(float(col['pterm']))
    iterm.append(float(col['iterm']))
    dterm.append(float(col['dterm']))
    ffterm.append(float(col['ffterm']))
    force.append(float(col['force']))

  # print(time)
  return [time, setpoint, velocity, pterm, iterm, dterm, ffterm, force]

def plot_data_single(data):
  x = np.arange(0,4*np.pi,0.1)   # start,stop,step
  print(x)
  y = np.sin(x)
  z = np.cos(x)
  x = data[0]
  print(x)
  y = data[1]
  z = data[2]
  plt.plot(x,y,x,z)
  plt.show()

def plot_data(data):
  # print ('data: ', data)
  time = data[0]
  setpoint = data[1]
  velocity = data[2]
  pterm = data[3]
  iterm = data[4]
  dterm = data[5]
  ffterm = data[6]
  force = data[7]

  ax1 = plt.subplot(411)
  ax1.plot(time, setpoint)
  ax1.plot(time, velocity)
  ax1.set_title('Cruise Control Example')
  ax1.set(ylabel='Velocity (m/s)')
  ax1.legend(['Setpoint', 'Velocity'])

  ax2 = plt.subplot(412)
  ax2.plot(time, force)
  ax2.set(ylabel='Total Force (N)')

  ax3 = plt.subplot(413)
  ax3.plot(time, pterm, time, iterm, time, dterm)
  ax3.set(ylabel='P,I,D Terms (N)')
  ax3.legend(['P', 'I', 'D'])

  ax4 = plt.subplot(414)
  ax4.plot(time, ffterm)
  ax4.set(xlabel='Time (s)', ylabel='FF Term (N)')

  plt.show()

def main():
  # dataFile = str(sys.argv[1])

  # data = load_data(dataFile)

  # plot_data(data)
  try:
    dataFile = str(sys.argv[1])

    data = load_data(dataFile)
    print("Data loaded")

    print("plotting data")
    plot_data(data)
    print("data plotted")

  except:
    print ('#########  Incorrect Usage  #########')
    print ('           python3 plot_cruise_control_data.py <data_file.txt>')
    sys.exit(2)


if __name__ == "__main__":
  main()