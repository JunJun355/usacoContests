def main():
    for i, line in enumerate(open(0)):
        line = line.strip()
        valve = line.split()[1]
        flow = int(line.split("=")[1].split(";")[0])
        edges = line.split("to ")[1].split(" ", 1)[1].split(", ")
        print(i, flow, len(edges), ' '.join(edges))


if __name__ == "__main__":
    main()
