/*
 * Project Euler problem 107.
 * It has associated file p107_network.txt with graph info.
 * Problem boils down to finding a minimum spanning tree, and solution should be found in O(mLogn) where m are edges and n are vertices.
 *
 * We are looking for the SAVING not the weight of the tree!
 * 
 * cargo run
 */

use std::collections::HashSet;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::time::{Instant};

fn main() {
    let start = Instant::now();

    if let Ok(lines) = read_lines("./p107_network.txt") {
        let mut node_count = 0usize;
        let mut edges = Vec::new();
        for (i, line) in lines.enumerate() {
            node_count += 1;
            if let Ok(row) = line {
                process_line(i, &row, &mut edges);
            }
        }
        edges.sort_by(|a, b| a.distance.cmp(&b.distance));
        // Note: dedup_by won't work since multiple vertices with the same
        // distance but different edges exist.
        // We are thus forced to sum above main diagonal. Main diagonal is empty,
        // because there are no vertices to the same node.
        let total_weight = edges.iter().
            filter(|edge| edge.start_node > edge.end_node).
            fold(0usize, |sum, val| sum + val.distance);
        println!("Total weight: {}", total_weight);

        let mut node_set = HashSet::new();
        let mut edge_set = HashSet::new();
        // Start with any node, we chose 0.
        node_set.insert(0);
        while node_set.len() < node_count {
            for edge in &edges {
                let has_start_node = node_set.contains(&edge.start_node);
                let has_end_node = node_set.contains(&edge.end_node);
                if has_start_node && !has_end_node {
                    node_set.insert(edge.end_node);
                    edge_set.insert(edge);
                    // We need to break, to start iterating from shortest edge.
                    break;
                } else if has_end_node && !has_start_node {
                    node_set.insert(edge.start_node);
                    edge_set.insert(edge);
                    // We need to break, to start iterating from shortest edge.
                    break;
                }
            }
        }

        let total_distance = edge_set.iter().fold(0usize, |sum, val| sum + val.distance);
        println!("Total distance: {}", total_distance);

        println!("Total savings: {}", total_weight - total_distance);

        let duration = start.elapsed();
        println!("Elapsed time: {:#?}", duration);
    }
}


// Light info about neigbours.
#[derive(Hash, Eq, PartialEq, Debug)]
struct Edge {
    distance: usize,
    start_node: usize,
    end_node: usize
}


// Process each line and assign values to edges.
fn process_line(node: usize, line: &String, edges: &mut Vec<Edge>) {
    for (i, part) in line.split(",").enumerate() {
        if part == "-" {
            continue;
        }
        // It's ok to panic when parsing the value.
        edges.push(Edge {distance: part.parse().unwrap(), start_node: i, end_node: node});
    }
}


// The output is wrapped in a Result to allow matching on errors.
// Returns an Iterator to the Reader of the lines of the file.
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}