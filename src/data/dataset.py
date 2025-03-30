import torch
from torch.utils.data import Dataset
from PIL import Image
import os
import torchvision.transforms as transforms

class LicensePlateDataset(Dataset):
    def __init__(self, root_dir, transform=None):
        self.root_dir = root_dir
        self.transform = transform if transform else transforms.Compose([
            transforms.Grayscale(),
            transforms.Resize((32, 32)),
            transforms.ToTensor(),
            transforms.Normalize((0.5,), (0.5,))
        ])
        
        self.samples = []
        self.load_dataset()
        
    def load_dataset(self):
        # 遍历数据集目录
        for class_folder in os.listdir(self.root_dir):
            class_path = os.path.join(self.root_dir, class_folder)
            if os.path.isdir(class_path):
                for image_file in os.listdir(class_path):
                    if image_file.endswith(('.png', '.jpg', '.jpeg')):
                        self.samples.append({
                            'image_path': os.path.join(class_path, image_file),
                            'label': class_folder
                        })
    
    def __len__(self):
        return len(self.samples)
    
    def __getitem__(self, idx):
        sample = self.samples[idx]
        image = Image.open(sample['image_path'])
        
        if self.transform:
            image = self.transform(image)
            
        return image, sample['label'] 