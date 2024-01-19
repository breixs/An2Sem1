interface ICars {
    brand: string,
    cost: number,
    registration_plate?: string,
    size?: string,
    nr_of_seats: number
};

let cars: ICars[] = [{
    brand: 'Mercedes',
    cost: 500000,
    registration_plate: 'TM_44_HAM',
    size: 'big',
    nr_of_seats: 7,
},
{
    brand: 'Renault',
    cost: 350000,
    registration_plate: 'TM_14_WYK',
    size: 'medium',
    nr_of_seats: 5,
},
{
    brand: 'BMW',
    cost: 250000,
    nr_of_seats: 6,
},
{
    brand: 'Volwswagen',
    cost: 200000,
    registration_plate: 'B_69_UEB',
    nr_of_seats: 4,
},
{
    brand: 'Audi',
    cost: 600000,
    nr_of_seats: 8,
},
{
    brand: 'Dacia',
    cost: 170000,
    registration_plate: 'SV_03_NIC',
    nr_of_seats: 4,
}
];

function criteria(cars: ICars[]): void {
    cars.forEach(cars => {
        if (cars.registration_plate === undefined)
            cars.registration_plate = 'unregistered';
        if (cars.size === undefined) {
            if (cars.nr_of_seats < 5)
                cars.size = 'small';
            if (cars.nr_of_seats > 5)
                cars.size = 'big';
        }
        if ((cars.brand = 'Mercedes') || (cars.brand = 'Audi') || (cars.brand = 'BMW'))
            cars.cost = cars.cost + 25000;
    });
}
criteria(cars);
function display(cars: ICars[]): ICars[] {
    return cars;
}
console.log(display(cars));