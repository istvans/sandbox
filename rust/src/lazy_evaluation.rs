use std::collections::HashMap;
use rand::Rng;
use std::thread;
use std::time::Duration;

struct Cacher<T, K, V>
where
    T: Fn(K) -> V,
    K: Copy + std::cmp::Eq + std::hash::Hash,
    V: Copy,
{
    calculation: T,
    value: HashMap<K, V>,
}

impl<T, K, V> Cacher<T, K, V>
where
    T: Fn(K) -> V,
    K: Copy + std::cmp::Eq + std::hash::Hash,
    V: Copy,
{
    fn new(calculation: T) -> Cacher<T, K, V> {
        Cacher {
            calculation,
            value: HashMap::new(),
        }
    }

    fn value(&mut self, arg: K) -> V {
        match self.value.get(&arg) {
            Some(v) => *v,
            None => {
                let v = (self.calculation)(arg);
                self.value.insert(arg, v);
                v
            }
        }
    }
}

fn generate_workout(intensity: u32, random_number: u32) {
    let mut expensive_result = Cacher::new(|num| {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    });

    if intensity < 25 {
        println!("Today, do {} pushups!", expensive_result.value(intensity));
        println!("Next, do {} situps!", expensive_result.value(intensity));
    } else {
        if random_number == 3 {
            println!("Take a break today! Remember to stay hydrated!");
        } else {
            println!(
                "Today, run for {} minutes!",
                expensive_result.value(intensity)
            );
        }
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    generate_workout(rng.gen_range(0..50), rng.gen_range(0..5));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn call_with_different_values() {
        let mut c = Cacher::new(|a| a);

        let v1 = c.value(1);
        assert_eq!(v1, 1);

        let v2 = c.value(2);
        assert_eq!(v2, 2);
    }

    #[test]
    fn call_with_a_string() {
        let mut c = Cacher::new(|a| a);

        let v1 = c.value("alma");
        assert_eq!(v1, "alma");

        let v2 = c.value("korte");
        assert_eq!(v2, "korte");
    }
}
