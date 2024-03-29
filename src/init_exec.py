from autoclone import AutoClone

if __name__ == "__main__":
    time_range = (3600 * 24) * 7 * 4 * 12 * 3 # three years
    AutoClone(time_range)()
